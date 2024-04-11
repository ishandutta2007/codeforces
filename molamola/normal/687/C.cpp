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

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int n, k, c[510];
int d[510][510];

void solve(){
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	d[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=k;j>=0;j--){
			for(int u=k;u>=j;u--){
				if(u >= c[i])d[j][u] |= d[j][u-c[i]];
				if(j >= c[i])d[j][u] |= d[j-c[i]][u-c[i]];
			}
		}
	}
	vector <int> v;
	for(int i=0;i<=k;i++)if(d[i][k])v.pb(i);
	printf("%d\n", sz(v));
	for(int e : v)printf("%d ", e);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}