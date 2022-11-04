/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

int n,k;
int pref[100][100];
string s[100];

int main(){

	cin >> n >> k;

	for (int i=1; i<=n; i++)
		cin >> s[i];

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++){
			while (pref[i][j]<(int)s[i].size() && pref[i][j]<(int)s[j].size()){
				if (s[i][pref[i][j]] == s[j][pref[i][j]])
					pref[i][j]++;
				else
					break;
			}
		}

	int ret = 0;

	for (int i=0; i<(1<<n); i++) if (__builtin_popcount(i)==k){
		
		vector <int> Q;

		for (int j=0; j<n; j++) if (i & (1<<j))
			Q.push_back(j+1);

		int ans = 0;

		for (int j=0; j<k; j++)
			for (int z=j+1; z<k; z++)
				ans+= pref[Q[j]][Q[z]];

		ret = max (ret , ans);
	}

	cout << ret << endl;

	return 0;
}