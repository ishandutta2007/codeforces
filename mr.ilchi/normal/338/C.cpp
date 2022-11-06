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
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int inf = 1000000000;

int n;
int dp[1<<8][1<<8];
LL a[10];
vector <LL> prime[10];

inline void setMin(int &A, int B) { A=min(A,B); }

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
		LL temp = a[i];
		for (LL j=2; j*j<=temp; j++){
			while (temp%j == 0){
				temp/=j;
				if (prime[i].empty() || prime[i].back()!=j)
					prime[i].push_back(j);
			}
		}
		if (temp>1)
			prime[i].push_back(temp);
	}
	for (int i=0; i<(1<<n); i++)
		for (int j=0; j<=i; j++) if ((j & i) == j)
			dp[i][j] = inf;
	dp[0][0] = 0;
	for (int mask=0; mask<(1<<n); mask++){
		for (int i=mask; (i>0) || (mask==0); i=((i-1)&mask)) if (dp[mask][i]!=inf){
			for (int j=0; j<n; j++) if ((mask & (1<<j)) == 0){
				for (int sub = i; sub>=0; sub=(sub-1)&i){
					LL cur = 1;
					for (int k=0; k<n; k++) if (sub & (1<<k)){
						if (a[j]/cur < a[k])
							cur = a[j]+1;
						else
							cur = cur * a[k];
					}
					if (a[j] % cur == 0){
						cur = a[j] / cur;
						int temp = dp[mask][i];
						for (int iter = 0; iter < (int)prime[j].size(); iter++){
							while(cur % prime[j][iter] == 0){
								cur /= prime[j][iter];
								temp++;
							}
						}
						setMin(dp[mask ^ (1<<j)][i ^ sub ^ (1<<j)], (prime[j].back() == a[j] ? temp : temp+1));
					}
					if (sub == 0)
						break;
				}
			}
			if (mask == 0)
				break;
		}
	}
	int ans = (1<<30);
	for (int mask=0; mask<(1<<n); mask++)
		ans = min(ans, dp[(1<<n)-1][mask] + (__builtin_popcount(mask)>1));
	cout << ans << endl;
	return 0;
}