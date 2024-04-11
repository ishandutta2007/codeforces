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

char P[20] = "Bulbasaur";

void solve(){
	char S[100010];
	scanf("%s", S+1);
	int Q[130] = {};
	for(int i=0;P[i];i++)Q[P[i]]++;
	int R[130] = {};
	for(int i=1;S[i];i++)R[S[i]]++;
	int ans = 1e9;
	for(int i=0;i<130;i++)if(Q[i])ans = min(ans, R[i] / Q[i]);
	printf("%d\n", ans);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}