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

int get(int x, int y){
	printf("0 %d %d\n", x, y);
	fflush(stdout);
	int r; scanf("%d", &r);
	return r;
}

vector <int> xy;
int R;

void Do(){
	int tx = -1e8;
	int res = get(tx, tx);
	tx += res; xy.pb(tx);
	while(tx <= 1e8){
		int flag = 0;
		for(int i=0;;i++){
			int nx = tx + (1<<i);
			if(nx > 1e8){flag = 1; break; }
			int temp = get(nx, nx);
			if(temp > 0){R = nx;}
			if(temp == (1<<i))continue;
			else{
				tx = nx + temp;
				xy.pb(tx);
				break;
			}
		}
		if(flag == 1)break;
	}
	vector <int> X, Y;
	for(int e : xy){
		int t = get(R, e);
		if(t == 0){
			Y.pb(e);
			t = get(e, R);
			if(t == 0)X.pb(e);
		}
		else X.pb(e);
	}
	printf("1 %d %d\n", sz(X), sz(Y));
	for(int e : X)printf("%d ", e); puts("");
	for(int e : Y)printf("%d ", e); puts("");
	fflush(stdout);
}

void solve(){
	Do();
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		// printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}