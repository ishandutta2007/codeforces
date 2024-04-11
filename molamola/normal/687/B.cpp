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

vector <Pi> P[1000010];

int n, k;
int isp[1000010];

void solve(){
	scanf("%d%d", &n, &k);
	for(int i=2;i<=1000000;i++)isp[i] = 1;
	for(int i=2;i<=1000000;i++){
		if(isp[i]){
			P[i].pb(Pi(i, 1));
			for(int j=i+i;j<=1000000;j+=i){
				int t = j, cnt = 0;
				while(t % i == 0)t /= i, ++cnt;
				P[j].pb(Pi(i, cnt));
			}
			for(int j=i+i;j<=1000000;j+=i)isp[j] = 0;
		}
	}
	map <int, int> M2;
	for(int i=2;i*i<=k;i++){
		while(k % i == 0)M2[i]++, k /= i;
	}
	if(k != 1)M2[k]++;
	map <int, int> M;
	for(int i=1;i<=n;i++){
		int x; scanf("%d", &x);
		for(auto e : P[x])if(M2.find(e.Fi) != M2.end())M[e.Fi] = max(M[e.Fi], e.Se);
	}
	int ok = 1;
	for(auto e : M2){
		if(e.Se > M[e.Fi])ok = 0;
	}
	printf("%s", ok ? "Yes" : "No");
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}