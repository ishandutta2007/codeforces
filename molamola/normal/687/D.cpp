#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <list>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int n, q, m;
int c[1010], cc[1010];
tuple<int, int, int, int> P[550000];

vector <int> L[1010];

void solve(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1;i<=m;i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		P[i] = tie(z, x, y, i);
	}
	sort(P+1, P+1+m);
	while(q--){
		int x, y; scanf("%d%d", &x, &y);
		for(int i=1;i<=n;i++){L[i].clear(); L[i].pb(i); c[i] = i;}
		int ans = -1;
		for(int i=m;i;i--){
			int u = get<3>(P[i]);
			if(x <= u && u <= y){
				int a = get<1>(P[i]);
				int b = get<2>(P[i]);
				if(c[a] == c[b]){
					if(cc[a] == cc[b]){
						ans = get<0>(P[i]);
						break;
					}
				}
				else{
					if(sz(L[c[a]]) < sz(L[c[b]]))swap(a, b);
					int t = 0;
					if(cc[a] == cc[b])t = 1;
					for(int e : L[c[b]]){ cc[e] ^= t; L[c[a]].pb(e); c[e] = c[a];}
				}
			}
		}
		printf("%d\n", ans);
	}
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}