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

vector <int> PP[130];

vector <int> print(int x){
	if(sz(PP[x]) > 0)return PP[x];
	printf("? %d\n", x);
	fflush(stdout);
	int a; scanf("%d", &a);
	vector <int> v;
	/*
	if(x == 1){v.pb(2); v.pb(3); }
	else if(x <= 63){v.pb(x+x+1); v.pb(x+x); v.pb(x/2); }
	else{ v.pb(x/2);}
	*/
	for(int i=0;i<a;i++){
		int x; scanf("%d", &x);
		v.pb(x);
	}
	return v;
}

void answer(int x){
	printf("! %d\n", x);
	fflush(stdout);
}

int is_d(int pre, int x, int dep){
	rep(i, dep){
		PP[x] = print(x);
		if(i == dep-1)break;
		int s = x;
		if(PP[x][0] == pre)x = PP[x][1];
		else x = PP[x][0];
		pre = s;
	}
	if(sz(PP[x]) == 1)return 1;
	else return 0;
}

void Do(int p, int pp, int dep, int h){
	if(dep == h){
		answer(pp);
		return;
	}
	if(sz(PP[pp]) == 0)PP[pp] = print(pp);
	if(sz(PP[pp]) == 2){
		answer(pp);
		return;
	}
	if(dep <= 4){
		int t = PP[pp][0];
		if(t == p)t = PP[pp][1];
		if(!is_d(pp, t, dep - 1)){
			Do(pp, t, dep+1, h);
		}
		else{
			int a = -1;
			rep(i, 3)if(PP[pp][i] != t && PP[pp][i] != p)a = PP[pp][i];
			Do(pp, a, dep+1, h);
		}
	}
	else{
		vector <int> v;
		v.pb(pp);
		int a = -1, b = -1;
		rep(i, 3){
			if(PP[pp][i] != p){
				if(a == -1)a = PP[pp][i];
				else b = PP[pp][i];
			}
		}
		v.pb(a); v.pb(b);
		PP[a] = print(a);
		PP[b] = print(b);
		if(sz(PP[a]) == 2){
			answer(a); return;
		}
		if(sz(PP[b]) == 2){
			answer(b); return;
		}
		int c[4] = {-1, -1, -1, -1};
		rep(i, 3){
			if(PP[a][i] != pp){
				if(c[0] == -1)c[0] = PP[a][i];
				else c[1] = PP[a][i];
			}
		}
		rep(i, 3){
			if(PP[b][i] != pp){
				if(c[2] == -1)c[2] = PP[b][i];
				else c[3] = PP[b][i];
			}
		}
		rep(i, 3){
			int e = c[i];
			PP[e] = print(e);
			if(sz(PP[e]) == 2){
				answer(e); return;
			}
		}
		answer(c[3]);
		return;
	}
}

void solve(){
	rep(i, 130)PP[i].clear();
	int h; scanf("%d", &h);
	if(h <= 4){
		for(int i=1;i<1<<h;i++){
			vector <int> v = print(i);
			if(sz(v) == 2){
				answer(i);
				return;
			}
		}
	}
	int a = 1;
	vector <int> v;
	int pre = -1;
	while(1){
		v.pb(a);
		PP[a] = print(a);
		if(sz(PP[a]) == 1)break;
		if(sz(PP[a]) == 2){
			answer(a);
			return;
		}
		int t = pre;
		pre = a;
		if(t == PP[a][0])a = PP[a][1];
		else a = PP[a][0];
	}
	int L = sz(v);
	int mL = (L + 3) / 2;
	if(L == 1){
		Do(a, PP[a][0], 2, h);
	}
	else{
		int p = v[sz(v) - mL + 1];
		int pp = v[sz(v) - mL];
		Do(p, pp, mL, h);
	}
}

int main(){
	int Tc = 1; scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}