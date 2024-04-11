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

int p[55];
int Find(int x){return p[x] == x ? x : p[x] = Find(p[x]); }

string name[55];

void solve(){
	int n, k; scanf("%d%d", &n, &k);
	rep(i, 26)name[i] = "A";
	rep(i, 26)name[i].pb('a' + i), name[i+26] = 'A' + i;
	for(int i=1;i<=n;i++)p[i] = i;
	for(int i=1;i<=n-k+1;i++){
		string s; cin >> s;
		if(s == "NO"){
			int x = Find(i), y = Find(i+k-1);
			if(x != y)p[x] = y;
		}
	}
	for(int i=1;i<=n;i++)printf("%s ", name[Find(i)].c_str()); puts("");
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}