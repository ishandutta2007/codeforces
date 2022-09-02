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

char S[200020];

void solve(){
	int n;
	scanf("%d", &n);
	scanf("%s", S+1);
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(S[i] == '>')break;
		ans++;
	}
	for(int i=n;i;i--){
		if(S[i] == '<')break;
		ans++;
	}
	printf("%d", ans);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}