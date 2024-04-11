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

int n, m;

void Go1(int x, int y, vector<string> &X, vector <pii> &ans);

void Go2(int x, int y, vector<string> &X, vector <pii> &ans){
	if(X[x][y] == 'L')return;
	else{
		Go1(x, y+1, X, ans);
		ans.pb(pii(x, y));
		X[x][y] = X[x+1][y] = 'L';
		X[x][y+1] = X[x+1][y+1] = 'R';
	}
}

void Go1(int x, int y, vector<string> &X, vector <pii> &ans){
	if(X[x][y] == 'U')return;
	else{
		Go2(x+1, y, X, ans);
		ans.pb(pii(x, y));
		X[x][y] = X[x][y+1] = 'U';
		X[x+1][y] = X[x+1][y+1] = 'D';
	}
}

void dfs(int x, int y, vector <string> &X, vector <pii> &ans){
	if(n % 2 == 0){
		if(y == m)return;
		Go1(x, y, X, ans);
		int nx = x + 2, ny = y;
		if(nx == n)nx = 0, ny = y + 1;
		dfs(nx, ny, X, ans);
	}
	else{
		if(x == n)return;
		Go2(x, y, X, ans);
		int nx = x, ny = y + 2;
		if(ny == m)nx = x + 1, ny = 0;
		dfs(nx, ny, X, ans);
	}
}

vector <pii> tr(vector <string> M){
	vector <pii> ans;
	dfs(0, 0, M, ans);
	return ans;
}

void solve(){
	scanf("%d%d", &n, &m);
	vector <string> A, B;
	rep(i, n){
		string s;
		cin >> s;
		A.pb(s);
	}
	rep(i, n){
		string s;
		cin >> s;
		B.pb(s);
	}
	auto X = tr(A), Y = tr(B);
	reverse(all(Y));
	for(auto e : Y)X.pb(e);
	printf("%d\n", sz(X));
	for(auto e : X)printf("%d %d\n", e.Fi + 1, e.Se + 1);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case %d: ", tc);
		solve();
	}
	return 0;
}