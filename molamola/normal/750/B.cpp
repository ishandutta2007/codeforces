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

int n, k;

void solve(){
	scanf("%d", &n);
	int P = 20000;
	int ok = 1;
	rep(i, n){
		int x; string s;
		cin >> x >> s;
		if(s == "South"){
			P -= x;
			if(P < 0)ok = 0;
		}
		else if(s == "North"){
			P += x;
			if(P > 20000)ok = 0;
		}
		else if(P == 0 || P == 20000)ok = 0;
	}
	if(P != 20000)ok = 0;
	printf("%s", ok ? "YES" : "NO");
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}