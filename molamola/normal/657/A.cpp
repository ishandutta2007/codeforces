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

void solve(){
	int n, d, h; scanf("%d%d%d", &n, &d, &h);
	if(2*h < d){
		printf("-1");
		return;
	}
	if(h == 1 && d == 1){
		if(n == 2)printf("1 2");
		else printf("-1");
		return;
	}
	vector <Pi> ans;
	int c = 1;
	rep(i, h)ans.emplace_back(c, c+1), c++;
	if(d-h > 0){
		ans.pb(Pi(1, c+1)); c++;
		rep(i, d-h-1)ans.pb(Pi(c, c+1)), c++;
		int x = n-c;
		rep(i, x)ans.pb(Pi(1, ++c));
	}
	else{
		int x = n-c, y = c-1;
		rep(i, x)ans.pb(Pi(y, ++c));
	}
	for(auto e : ans)printf("%d %d\n", e.Fi, e.Se);
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}