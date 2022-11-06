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

const int maxn = 1050;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int ans[maxn];
vector < pair < int, pair < int, int > > > queries;
vector < pair < int, pair < int, int > > > newQueries;
vector < int > q1, q2;
int used1[maxn];
int used2[maxn];

void solution( int realN ) {
	for ( int j = 0; j < maxn; j++ )
		ans[j] = inf;
	int n = 1;
	while ( n < realN )
		n *= 2;
	queries.pb( mp( 1, mp( 1, n ) ) );
	while ( !queries.empty() ) {
		newQueries.clear();
		q1.clear();
		q2.clear();
		for ( int j = 0; j < maxn; j++ )
			used1[j] = used2[j] = false;
		int sz = queries.size();
		for ( int j = 0; j < sz; j++ ) {
			int len = queries[j].s.s;
			if ( len == 1 )
				continue;
			int x = queries[j].f;
			int y = queries[j].s.f;
			int mid = ( x + x + len - 1 ) >> 1;
			for ( int i = x; i <= mid; i++ ) {
				q1.pb( i );
				used1[y + i - x + len / 2] = true;
			}
			for ( int i = mid + 1; i <= x + len - 1; i++ ) {
				q2.pb( i );
				used2[y + i - mid - 1] = true;
			}
			newQueries.pb( mp( x, mp( y, len >> 1 ) ) );
			newQueries.pb( mp( x + len / 2, mp( y + len / 2, len / 2 ) ) );
		}
		queries.clear();
		queries = newQueries;
		int sz1 = q1.size();
		while ( sz1 && q1[sz1 - 1] > realN ) {
			q1.pop_back();
			--sz1;
		}
		int sz2 = q2.size();
		while ( sz2 && q2[sz2 - 1] > realN ) {
			q2.pop_back();
			--sz2;
		}
		if ( !q1.empty() ) {
			int sz = q1.size();
			cout << sz << endl;
			for ( int j = 0; j < sz; j++ )
				cout << q1[j] << ' ';
			cout << endl;
			for ( int j = 1; j <= realN; j++ ) {
				int x;
				scanf ( "%d", &x );
				if ( used1[j] )
					ans[j] = min( ans[j], x );
			}
		}
		if ( !q2.empty() ) {
			int sz = q2.size();
			cout << sz << endl;
			for ( int j = 0; j < sz; j++ )
				cout << q2[j] << ' ';
			cout << endl;
			for ( int j = 1; j <= realN; j++ ) {
				int x;
				scanf ( "%d", &x );
				if ( used2[j] )
					ans[j] = min( ans[j], x );
			}
		}
	}
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    solution( n );
    cout << -1 << endl;
    for ( int j = 1; j <= n; j++ )
        cout << ans[j] << ' ';
    cout << endl;
    return 0;
}