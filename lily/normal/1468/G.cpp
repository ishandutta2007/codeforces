#include <bits/stdc++.h>

using namespace std;
const int N = 200010;
const double EPS = 1e-8;
int _w;

int dcmp( double x ) {
    if( fabs(x) < EPS ) return 0;
    else return x < 0 ? -1 : 1;
}

struct Point {
    double x, y;
    
    Point operator+( const Point &rhs ) const {
	return (Point){x + rhs.x, y + rhs.y};
    }
    Point operator-( const Point &rhs ) const {
	return (Point){x - rhs.x, y - rhs.y};
    }
    Point operator*( double rhs ) const {
	return (Point){x * rhs, y * rhs};
    }
    Point operator/( double rhs ) const {
	return (Point){x / rhs, y / rhs};
    }
};

double Cross( Point A, Point B ) {
    return A.x * B.y - A.y * B.x;
}
double Length( Point A ) {
    return sqrt(A.x * A.x + A.y * A.y);
}

Point LineIntersection( Point P, Point v, Point Q, Point w ) {
    return P + v * Cross(w, P-Q) / Cross(v, w);
}

int n, h;
Point P[N], Q;

Point update( Point H, Point nH ) {
    if( dcmp(Cross(H-Q, nH-Q)) <= 0 )
	return nH;
    else return H;
}

void solve() {
    double ans = 0;
    Point H = P[n];
    for( int i = n; i >= 2; --i ) {
	Point B = P[i];
	Point A = P[i-1];
	
	if( dcmp(Cross(A-Q, H-Q)) < 0 && dcmp(Cross(B-Q, H-Q)) <= 0 ) {
	    ;
	} else if( dcmp(Cross(A-Q, H-Q)) >= 0 && dcmp(Cross(B-Q, H-Q)) >= 0 ) {
	    ans += Length(A-B);
	} else {
	    Point T = LineIntersection( A, B-A, Q, H-Q );
	    ans += Length(A-T);
	}
	
	H = update(H, A);
    }

    printf( "%.20lf\n", ans );
}

int main() {
    _w = scanf( "%d%d", &n, &h );
    for( int i = 1; i <= n; ++i ) {
	int x, y;
	_w = scanf( "%d%d", &x, &y );
	P[i] = (Point){x, y};
    }
    Q = P[n];
    Q.y += h;
    solve();
    return 0;
}