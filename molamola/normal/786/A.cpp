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

int n, A[7070], B[7070], a, b;

int chk[14040];

void solve(){
	scanf("%d", &n);
	scanf("%d", &a);
	for(int i=1;i<=a;i++)scanf("%d", A+i);
	scanf("%d", &b);
	for(int i=1;i<=b;i++)scanf("%d", B+i);
	for(int i=0;i<n+n;i++)chk[i] = 0;
	queue <int> que; que.push(0); que.push(1);
	chk[0] = chk[1] = 1;
	int deg[14040] = {};
	rep(i, n)deg[i+i] = a, deg[i+i+1] = b;
	while(!que.empty()){
		int t = que.front(); que.pop();
		int is_b = (t & 1);
		if(!is_b){
			int x = t >> 1;
			for(int i=1;i<=b;i++){
				int y = (x - B[i] + n) % n;
				if(chk[y+y+1] != 0)continue;
				if(chk[t] == 1){
					chk[y+y+1] = 2;
					que.push(y+y+1);
				}
				else{
					deg[y+y+1]--;
					if(deg[y+y+1] == 0)que.push(y+y+1), chk[y+y+1] = 1;
				}
			}
		}
		else{
			int x = t >> 1;
			for(int i=1;i<=a;i++){
				int y = (x - A[i] + n) % n;
				if(chk[y+y] != 0)continue;
				if(chk[t] == 1){
					chk[y+y] = 2;
					que.push(y+y);
				}
				else{
					deg[y+y]--;
					if(deg[y+y] == 0)que.push(y+y), chk[y+y] = 1;
				}
			}
		}
	}
	rep(u, 2){
		for(int i=1;i<n;i++){
			if(chk[i+i+u] == 0)printf("Loop ");
			else if(chk[i+i+u] == 1)printf("Lose ");
			else printf("Win ");
		}
		puts("");
	}
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}