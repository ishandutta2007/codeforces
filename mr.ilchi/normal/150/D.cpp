/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 150+10;

int l;
int a[MAXN];
int ans [MAXN][MAXN];
int full[MAXN][MAXN][MAXN];
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> l;
	for (int i=1; i<=l; i++)
		cin >> a[i];
	cin >> s;
	memset(full,-1,sizeof full);
	for (int len=1; len<=l; len++){
		for (int i=0; i+len<=l; i++){
			for (int z=0; z<=i; z++){
				int &cur = full[i][len][z];
				for (int k=1; k<len; k++){
					int f1 = full[i][k][z] , f2 = full[i+k][len-k][0]; if (f1!=-1 && f2!=-1) cur = max(cur,f1+f2);
					int f3 = full[i][k][0] , f4 = full[i+k][len-k][z]; if (f3!=-1 && f4!=-1) cur = max(cur,f3+f4);
				}
				if (z!=0 && a[2*z]!=-1 && full[i][len][0]!=-1) cur = max(cur,a[2*z]+full[i][len][0]); 
				if (len>1 && s[i]==s[i+len-1]){
					if (len!=2)
						cur=max(cur,full[i+1][len-2][z+1]);
					else
						cur=max(cur,a[2*z+2]);
				}
				if (len==1 && a[2*z+1]!=-1) cur=max(cur,a[2*z+1]);
			}
		}
	}
	for (int len=1; len<=l; len++){
		for (int i=0; i+len<=l; i++){
			ans[i][len] = max(ans[i][len],full[i][len][0]);
			for (int j=1; j<len; j++)
				ans[i][len] = max(ans[i][len], ans[i][j]+ans[i+j][len-j]);
		}
	}
	cout << ans[0][l] << endl;
	return 0;
}