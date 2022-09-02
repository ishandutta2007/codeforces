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
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;
typedef long double ldouble;

int n, k;
int A[1010];
int temp[4030];

void solve(){
	scanf("%d%d", &n, &k);
	rep(i, k){
		int x; scanf("%d", &x);
		A[x] = 1;
	}
	vector <int> v;
	for(int i=0;i<=1000;i++)if(A[i])v.pb(i);
	if(v[0] > n || v.back() < n){
		puts("-1");
		return;
	}
	if(A[n] == 1){
		printf("1\n");
		return;
	}
	for(int &e : v)e -= n;
	int *D = temp + 2010;
	for(int i=-2000;i<=2000;i++)D[i] = -1;
	queue <int> que;
	for(int e : v)D[e] = 1, que.push(e);
	while(!que.empty()){
		int t = que.front(); que.pop();
		for(int &e : v){
			if(t + e < -2000 || t + e > 2000)continue;
			if(D[t + e] == -1)D[t + e] = D[t] + 1, que.push(t + e);
		}
	}
	printf("%d\n", D[0]);
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}