#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <bitset>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, a[ 5 ], b[ 5 ], sum = 0, ans = 0;

void action1()
{
  int num = a[1] / 3;
  ans += 2 * num;
  a[1] -= 3 * num;
  a[3] += num;
}

void action2()
{
  int num = a[2] / 3;
  ans += 2 * num;
  a[2] -= 3 * num;
  a[3] += 2 * num;
}

void action3()
{
  int num = min( a[1], a[2] );
  ans += num;
  a[1] -= num;
  a[2] -= num;
  a[3] += num;
}

void action4()
{
  int num = min( a[2], a[4] );
  ans += num;
  a[2] -= num;
  a[4] -= num;
  a[3] += 2 * num; 
}

void action5()
{
  int num = min( a[1], a[4] / 2 );
  ans += 2 * num;
  a[1] -= num;
  a[4] -= 2 * num;
  a[3] += 3 * num;
}

void action6()
{
  int num = min( a[1], a[3] );
  ans += num;
  a[1] -= num;
  a[3] -= num;
  a[4] += num;
}

void action7()
{
  int num = min( a[2], a[3] / 2 );
  ans += 2 * num;
  a[2] -= num;
  a[3] -= 2 * num;
  a[4] += 2 * num;
}

void action8()
{
  int num = min( a[1] / 2, a[4] );
  ans += 2 * num;
  a[1] -= 2 * num;
  a[4] -= num;
  a[3] += 2 * num;
}

void action9()
{
  int num = a[2] / 2;
  ans += 2 * num;
  a[2] -= 2 * num;
  a[4] += num;
}

void run( int id )
{
  if ( id == 1 ) action1();
  if ( id == 2 ) action2();
  if ( id == 3 ) action3();
  if ( id == 4 ) action4();
  if ( id == 5 ) action5();
  if ( id == 6 ) action6();
  if ( id == 7 ) action7();
  if ( id == 8 ) action8();
  if ( id == 9 ) action9();
}

int fun( vector< int > p )
{
	a[1] = b[1];
	a[2] = b[2];
	a[3] = b[3];
	a[4] = b[4];
	ans = 0;
	for ( int i = 0; i < p.size(); i++ ) run( p[i] );
	if ( a[1] + a[2] > 0 ) return 1000000000;
	return ans;
}



int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ )
    {
    	int x; scanf("%d", &x);
    	b[x]++; sum += x;
    }
    int answer = 1000000000;
    vector< int > p;
    for ( int i = 1; i <= 9; i++ ) p.pb( i );
    do
    {
        answer = min( answer, fun( p ) );
    } while ( next_permutation( p.begin(), p.end() ) );
    if ( answer == 1000000000 ) answer = -1;
    cout << answer << "\n";
    return 0;
}