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
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef complex<double> point;

const int mod = 1000000007;

int n,k;
int sum[2005];
int f[2005][2005];
string s;

inline void add (int &A, const int &B) { A = (A+B) % mod; }
inline int mul (const int &A, const int &B) { return (LL)A*B%mod; }

int main(){
	cin >> n >> k;
	cin >> s;
	f[n][0] = 1;
	for (int i=n-1; i>=0; i--)
		f[i][0] = mul(f[i+1][0], s[i]-'a'+1);
	for (int i=n-1; i>=0; i--){
		int len = n-i;
		for (int j=1; j<=k; j++){
			add(f[i][j], mul(f[i+1][j], s[i]-'a'));
			if (j>=len)
				add(f[i][j], mul(f[i+1][j-len], 'z'-s[i]));
			add(f[i][j], sum[j]);
		}
		for (int j=1; j<=k; j++)
			add(sum[j], mul(f[i+1][j], s[i]-'a'));
		for (int j=len; j<=k; j++) if (f[i+1][j-len]){
			int cur = mul(f[i+1][j-len], 'z'-s[i]);
			for (int p=i-1, t=j+len; p>=0 && t<=k; p--, t+=len)
				add(f[p][t], cur);
		}
	}
	cout << f[0][k] << endl;
	return 0;
}