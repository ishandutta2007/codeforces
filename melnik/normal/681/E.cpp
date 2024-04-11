#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

vector < pair < ld, ld > > angle;
int X0, Y0, v, t;

struct point {
	ld X, Y;
	point () {}
	point ( ld _X, ld _Y ) {
		X = _X;
		Y = _Y;
	}
};

void insert( ld angle1, ld angle2 ) {
	if ( angle2 > angle1 ) {
		angle.pb( mp( angle1, angle2 ) );
		return;
	}
	angle.pb( mp( angle1, 2.0L * M_PI ) );
	angle.pb( mp( 0.0L, angle2 ) );
}

ll getDist( int x1, int y1, int x2, int y2 ) {
	return 1LL * ( x1 - x2 ) * ( x1 - x2 ) + 1LL * ( y1 - y2 ) * ( y1 - y2 );
}

ld getDistLD( int x1, int y1, ld x2, ld y2 ) {
	return 1.0L * ( 1.0L * x1 - x2 ) * ( 1.0L * x1 - x2 ) +
			1.0L * ( 1.0L * y1 - y2 ) * ( 1.0L * y1 - y2 );
}

bool inside( int x, int y, int r ) {
	return getDist( X0, Y0, x, y ) <= 1LL * r * r;
}

void findIntersection( int x, int y, ll r1, ll r2, point &intersection1, point &intersection2 ) {
	ld A = -2.0L * x;
	ld B = -2.0L * y;
	ld C = -1.0L * r2 + 1.0L * r1 + 1.0L * x * x + 1.0L * y * y;
	ld comp = A * A + B * B;
	ld d = 1.0L * r1 - ( 1.0L * C / comp ) * C;
	ld mult = sqrt( d / comp );
	ld X00 = ( -A / comp ) * C;
	ld Y00 = ( -B / comp ) * C;
	intersection1 = point( X00 + B * mult, Y00 - A * mult );
	intersection2 = point( X00 - B * mult, Y00 + A * mult );
}

void calcTangents( int x, int y, int r, point &tangent1, point &tangent2 ) {
	x -= X0;
	y -= Y0;
	findIntersection( x, y, getDist( 0, 0, x, y ) - 1LL * r * r, 1LL * r * r, tangent1, tangent2 );
}

bool haveIntersection( int x, int y, int r ) {
	ll R = 1LL * t * v;
	ld dist = sqrt( getDist( X0, Y0, x, y ) );
	return 1.0L * R <= dist + 1.0L * r && 1.0L * R >= dist - 1.0L * r;
}

ld getAngle( ld x, ld y ) {
	// x -= 1.0L * X0;
	// y -= 1.0L * Y0;
	ld Angle = atan2( y, x );
	if ( Angle < 0 )
		Angle = 2.0L * M_PI + Angle;
	return Angle;
}

void calc( int x, int y, int r ) {
	if ( !r )
		return;
	if ( inside( x, y, r ) ) {
		insert( 0.0, 2.0 * M_PI );
		return;
	}
	if ( 1.0L * getDist( X0, Y0, x, y ) >=
			1.0L * ( 1.0L * v * t + 1.0 * r ) * ( 1.0L * v * t + 1.0 * r ) )
		return;
	point tangent1, tangent2;
	calcTangents( x, y, r, tangent1, tangent2 );
	point intersection1, intersection2;
	point ans1, ans2;
	ans1 = tangent1;
	ans2 = tangent2;
	if ( haveIntersection( x, y, r ) ) {
		findIntersection( x - X0, y - Y0, 1LL * v * t * v * t, 1LL * r * r, intersection1, intersection2 );
		if ( getDistLD( X0, Y0, intersection1.X, intersection1.Y ) < 
				getDistLD( X0, Y0, tangent1.X, tangent1.Y ) ) {
			ans1 = intersection1;
			ans2 = intersection2;
		}
	}
	ld angle1 = getAngle( ans1.X, ans1.Y );
	ld angle2 = getAngle( ans2.X, ans2.Y );
	if ( angle1 < angle2 )
		swap( angle1, angle2 );
	ld diff = angle1 - angle2;
	if ( diff < M_PI )
		insert( angle2, angle1 );
	else
		insert( angle1, angle2 );
}

// ld normolize( ld Angle ) {
// 	return 180.0L * Angle / M_PI;
// }

// void out() {
// 	cout << fixed << setprecision( 7 ) << normolize( getAngle( 1, 1 ) ) << endl;
// 	cout << fixed << setprecision( 7 ) << normolize( getAngle( -1, 1 ) ) << endl;
// 	cout << fixed << setprecision( 7 ) << normolize( getAngle( -1, -1 ) ) << endl;
// 	cout << fixed << setprecision( 7 ) << normolize( getAngle( 1, -1 ) ) << endl;
// }

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
   	// out();
    scanf ( "%d%d%d%d", &X0, &Y0, &v, &t );
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ ) {
    	int x, y, r;
    	scanf ( "%d%d%d", &x, &y, &r );
    	calc( x, y, r );
    }
    int sz = angle.size();
    // for ( int j = 0; j < sz; j++ ) {
    // 	cout << fixed << setprecision( 7 ) << angle[j].f << ' ' << angle[j].s << endl;
    // }
    ld ans = 0.0L;
    sort( angle.begin(), angle.end() );
    ld l, r;
    l = r = 0.0L;
    for ( int j = 0; j < sz; j++ ) {
    	if ( angle[j].f > r ) {
    		ans += r - l;
    		l = angle[j].f;
    	}
    	r = max( r, angle[j].s );
    }
    ans += r - l;
    cout << fixed << setprecision( 20 ) << 1.0L * ans / ( 2.0L * M_PI );
    return 0;
}