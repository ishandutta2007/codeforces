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

void solve(){
	int n, p[10010];
	scanf("%d", &n);
	for(int i=1;i<=n;i++)scanf("%d", p+i);
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(p[p[i]] == i)ans++;
		if(p[i] == i)ans++;
	}
	printf("%d\n",ans / 2);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}