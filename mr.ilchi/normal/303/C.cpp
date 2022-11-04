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

int n,k,len,code;
int a[1<<20],vis[1<<20],mark[1<<20],par[1<<20],index[100];
vector <pii> Q[1<<20];

/*
inline int root (int v){
	return (v!=par[v]) ? (par[v] = root(par[v])) : (v);
}

inline bool go(){
	code++;
	int tot = 0, comp = 0;
	for (int i=0; i<len; i++)
		for (int j=0; j<(int)Q[index[i]].size(); j++){
			int f0 = Q[index[i]][j].first;
			int f1 = Q[index[i]][j].second;
			if (mark[f0]!=code) { mark[f0] = code; par[f0] = f0; comp++; tot++; }
			if (mark[f1]!=code) { mark[f1] = code; par[f1] = f1; comp++; tot++; }
			if (root(f0)!=root(f1)){
				par[f0] = par[f1];
				comp--;
			}
		}
	return (tot-comp) <= k;
}
*/
int main(){
	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a,a+n);
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			if ((int)Q[a[j]-a[i]].size() <= k)
				Q[a[j]-a[i]].push_back(pii(i,j));
	for (int i=1; i<=a[n-1]; i++){
		len = 0;
		int Count = 0;
		int bound = k * (k+1) / 2;
		for (int j=i; j<=a[n-1] && Count<=bound; j+=i){
			Count+= (int)Q[j].size();
			if (!Q[j].empty())
				index[len++] = j;
			if ((int)Q[j].size() > k){
				Count = bound + 1;
				break;
			}
		}
		if (Count>bound) continue;
		int cur = 0;
		code++;
		for (int rep=0; rep<len && cur<=k; rep++){
			for (int t=0; t<(int)Q[index[rep]].size() && cur<=k; t++){
				int f0 = Q[index[rep]][t].first;
				int f1 = Q[index[rep]][t].second;
				if (vis[f0] != code) { vis[f0]=code; if (mark[a[f0]%i] != code) { mark[a[f0]%i]=code; } else cur++; }
				if (vis[f1] != code) { vis[f1]=code; if (mark[a[f1]%i] != code) { mark[a[f1]%i]=code; } else cur++; }
			}
		}
		if (cur <= k){
			cout << i << endl;
			break;
		}
	}
	return 0;
}