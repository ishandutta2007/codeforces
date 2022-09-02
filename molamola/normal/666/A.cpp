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

using namespace std;
typedef long long ll;
typedef pair<int,int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

int ok[10010][2];

void solve(){
	string s; cin >> s;
	int l = sz(s); s += "00000000";
	set <string> S;
	ok[l][0] = ok[l][1] = 1;
	for(int i=l-1;i>=5;i--){
		if(ok[i+2][1] || (s.substr(i, 2) != s.substr(i+2, 2) && ok[i+2][0]))ok[i][0] = 1, S.insert(s.substr(i, 2));
		if(ok[i+3][0] || (s.substr(i, 3) != s.substr(i+3, 3) && ok[i+3][1]))ok[i][1] = 1, S.insert(s.substr(i, 3));
	}
	printf("%d\n", sz(S));
	for(auto e : S)cout << e << "\n";
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}