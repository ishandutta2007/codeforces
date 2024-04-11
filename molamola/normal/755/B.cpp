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
#include <list>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

set <string> A, B;

void solve(){
	int n, m; scanf("%d%d", &n, &m);
	rep(i, n){
		string s; cin >> s;
		A.insert(s);
	}
	rep(i,m){
		string s; cin >> s;
		B.insert(s);
	}
	int t = 0;
	for(auto e : A)if(B.find(e) != B.end())++t;
	if(t % 2 == 0){n -= t, m -= t;
		if(n > m)puts("YES");
		else puts("NO");
	}
	else{
		n -= t; m -= t;
		if(n >= m)puts("YES");
		else puts("NO");
	}
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}