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

int m;
pair< int, int > p[ 1010 ][ 11 ][ 11 ];
bool f[ 1010 ][ 11 ][ 11 ];
string s;
vector< int > ans;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	cin >> s >> m;
	f[0][0][0] = true;
	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j <= 10; j++ )
			for ( int k = 0; k <= 10; k++ )
				for ( int d = 1; d <= 10; d++ )
				{
					if ( s[d - 1] == '0' ) continue;
					if ( !f[i][j][k] ) continue;
					//cout << "! " << d << endl;
					if ( d == j ) continue;
					int s1, s2;
					if ( i % 2 == 0 ) 
					{
						s1 = d; s2 = k;
						if ( s1 > s2 && s1 - s2 <= 10 ) 
						{
							f[i + 1][d][s1 - s2] = true;
							p[i + 1][d][s1 - s2] = mp( j, k );
						}
					}
					if ( i % 2 == 1 )
					{
						s1 = k; s2 = d;
						if ( s1 < s2 && s2 - s1 <= 10 )
						{
							f[i + 1][d][s2 - s1] = true;
							p[i + 1][d][s2 - s1] = mp( j, k );
						}
					}
				} 
	for ( int i = 0; i <= 10; i++ )
		for ( int j = 0; j <= 10; j++ )
		{
			if ( f[m][i][j] )
			{
				cout << "YES\n";
				int ii = m;
				int jj = i;
				int kk = j;
				while ( ii > 0 )
				{
					//cout << ii << " " << jj << " " << kk << endl;   
					ans.pb( jj );
					pair< int, int > pp = p[ii][jj][kk];
					ii = ii - 1;
					jj = pp.first;
					kk = pp.second;
				}
				reverse( ans.begin(), ans.end() );
				for ( int i = 0; i < ans.size(); i++ ) cout << ans[i] << " ";
				return 0;
			}
		}
	cout << "NO\n";
    return 0;
}