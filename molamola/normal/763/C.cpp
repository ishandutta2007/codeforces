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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;

int m, n;
int p[100010];
unordered_set <int> S;

int pw(int x, int y){
	int res = 1;
	while(y){
		if(y & 1)res = (ll)res * x % m;
		x = (ll)x * x % m;
		y >>= 1;
	}
	return res;
}

int F;

void Do(){
	int x = p[2] - p[1];
	if(x < 0)x += m;
	for(int t=1;t<=n-1;t++){
		int dx = (ll)x * pw(t, m-2) % m;
		int f = 0;
		for(int a=0;a<n;a++){
			int y = (p[1] + (ll)a * dx) % m;
			if(S.find(y) == S.end()){break;}
			f = a;
		}
		int g = 0;
		for(int a=0;a<n;a++){
			int y = (p[1] - (ll)a * dx) % m;
			if(y < 0)y += m;
			if(S.find(y) == S.end()){break;}
			g = a;
		}
		if(f + g == n-1){
			int y = (p[1] - (ll)g * dx) % m;
			if(y < 0)y += m;
			if(F == 0){
				printf("%d %d\n", y, dx);
			}
			else{
				int z = (y + (ll)dx * n) % m;
				printf("%d %d\n", z, dx);
			}
			exit(0);
		}
	}
}

void solve(){
	scanf("%d%d", &m, &n);
	if(n == m){
		printf("0 1\n");
		return;
	}
	if(n == 1){
		int x; scanf("%d", &x);
		printf("%d %d\n", x, 0);
		return;
	}
	for(int i=1;i<=n;i++)scanf("%d", p+i);
	if(2*n > m){
		F = 1;
		vector <int> v;
		int c[200020] = {};
		for(int i=1;i<=n;i++)c[p[i]] = 1;
		for(int i=0;i<m;i++)if(c[i] == 0)v.pb(i);
		n = sz(v);
		for(int i=1;i<=n;i++)p[i] = v[i-1];
	}
	if(n == 1){
		printf("%d %d\n", (p[1]+1)%m, 1);
		return;
	}
	for(int i=1;i<=n;i++)S.insert(p[i]);
	Do();
	swap(p[1], p[2]);
	Do();
	printf("-1\n");
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}