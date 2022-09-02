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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;

void solve(){
	char S[100010];
	scanf("%s", S+1);
	int L = (int)strlen(S+1);
	int c = 0;
	for(int i=1;i<=L;i++)if(S[i] == '#')c++;
	int l = 0, r = 0;
	for(int i=1;i<=L;i++){
		if(S[i] == '(')l++;
		if(S[i] == ')')r++;
	}
	if(l < r + c){
		puts("-1");
		return;
	}
	int now = 0;
	int last = -1;
	for(int i=L;i;i--)if(S[i] == '#' && last == -1)last = i;
	vector <int> ans;
	for(int i=1;i<=L;i++){
		int x = 0;
		if(S[i] == '(')x = 1;
		else if(S[i] == ')')x = -1;
		else if(i != last)x = -1;
		else x = -(l - r - c + 1);
		now += x;
		if(now < 0){
			puts("-1");
			return;
		}
		if(S[i] == '#')ans.pb(-x);
	}
	for(int e : ans)printf("%d\n", e);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}