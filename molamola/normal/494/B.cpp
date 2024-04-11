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

char S[100010], T[100010];
int fail[100010];

const int MOD = 1e9 + 7;
int s[100010], ss[100010];

void solve(){
	scanf("%s%s", S+1, T+1);
	fail[0] = -1;
	int LS = (int)strlen(S+1);
	int LT = (int)strlen(T+1);
	for(int i=1;i<=LT;i++){
		int t = fail[i-1];
		while(t != -1 && T[t+1] != T[i])t = fail[t];
		fail[i] = t + 1;
	}
	int chk[100010] = {};
	for(int i=1, j=0;i<=LS;i++){
		while(j != -1 && S[i] != T[j+1])j = fail[j];
		++j;
		if(j == LT)chk[i] = 1, j = fail[j];
	}
	s[0] = ss[0] = 1;
	for(int i=1, p = -1;i<=LS;i++){
		if(chk[i])p = i - LT;
		int temp = 0;
		if(p != -1){
			temp = ss[p];
		}
		s[i] = (s[i-1] + temp) % MOD;
		ss[i] = (ss[i-1] + s[i]) % MOD;
	}
	printf("%d\n", (s[LS] + MOD - 1)%MOD);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}