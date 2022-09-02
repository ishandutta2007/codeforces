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
typedef tuple<int, int, int, int> t4;
typedef pair<ll, ll> PL;
typedef long double ldouble;

int n, m;
int c[200020];
int D[200020], pre[200020];

int gc(int x, int y){return y == 0 ? x : gc(y, x%y); }
vector <int> V[200020];

void ext(int a, int b, int &x, int &y){
	//ax - by = 1;
	if(b == 0){
		x = 1; y = 0;
	}
	else{
		int tx, ty;
		ext(b, a%b, tx, ty);
		x = -ty;
		y = a / b * x - tx;
	}
}

int get(int a, int b){
	int t = gc(a, m);
	int tm = m;
	a /= t; b /= t; tm /= t;
	int x, y; ext(a, tm, x, y);
	x %= tm;
	if(x < 0)x += tm;
	x = (ll)x * b % tm;
	return x;
}

void solve(){
	scanf("%d%d", &n, &m);
	rep(i, n){
		int x; scanf("%d", &x);
		c[x] = 1;
	}
	for(int i=0;i<m;i++)if(c[i] == 0){
		V[gc(i, m)].pb(i);
	}
	pre[1] = -1;
	for(int i=1;i<=m;i++){
		D[i] += sz(V[i]);
		for(int j=i+i;j<=m;j+=i){
			if(m % j == 0){
				if(D[j] < D[i]){
					D[j] = D[i];
					pre[j] = i;
				}
			}
		}
	}
	printf("%d\n", D[m]);
	int t = m;
	vector <int> v;
	while(t != -1){
		for(int e : V[t])v.pb(e);
		t = pre[t];
	}
	reverse(all(v));
	int p = 1;
	for(int e : v){
		int t;
		printf("%d ", t = get(p, e));
		p = e;
	}
	puts("");
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}