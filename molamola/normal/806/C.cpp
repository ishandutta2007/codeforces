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
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef tuple<int, int, int, int> t4;
typedef long double ldouble;

int n;
ll A[100010];

void solve(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%lld", A+i);
	int B[60] = {};
	multiset <ll> S;
	for(int i=1;i<=n;i++){
		if(A[i] == (A[i] & -A[i])) B[__builtin_ctzll(A[i])]++;
		else S.insert(A[i]);
	}
	for(int i=1;i<60;i++) while(B[i] > B[i-1]){
		B[i]--;
		S.insert(1LL << i);
	}
	if(sz(S) * 2 > n){ puts("-1"); return; }
	int cnt = 0;
	for(int i=59;i>=0;i--)while(B[i]){
		++cnt;
		for(int j=0;j<=i;j++) B[j]--;
		if(sz(S)){
			ll t = *(--S.end());
			if(t > (1LL << (i+1))){ puts("-1"); return; }
			S.erase(S.find(t));
		}
		else{
			for(int j=0;j<=i;j++)if(B[j] > B[j+1]){B[j]--; break; }
		}
	}
	if(sz(S)){ puts("-1"); return; }
	int r = 0;
	for(int i=1;i<=n;i++)if(A[i] == 1) ++r;
	for(int i=cnt;i<=r;i++) printf("%d ", i); puts("");
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1; tc<=Tc; tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}