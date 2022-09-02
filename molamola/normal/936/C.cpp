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
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<ldouble, ldouble> pdd;

char A[2020], B[2020];
vector <int> ans;
int N;

void Do(int x) {
	ans.pb(x);
	reverse(A+1, A+1+N);
	reverse(A+1+x, A+1+N);
}

void solve() {
	scanf("%d", &N);
	scanf("%s%s", A+1, B+1);
	int cnt[26] = {};
	for(int i=1;i<=N;i++) {
		cnt[A[i] - 'a']++;
		cnt[B[i] - 'a']--;
	}
	rep(i, 26) if(cnt[i] != 0) {
		puts("-1");
		return;
	}
	for(int i=1;i<=N;i++) {
		char c = B[i];
		int f = -1;
		for(int j=1;j<=N+1-i;j++) if(A[j] == c) { f = j; break; }
		Do(N - f);
		Do(1);
		Do(N - 1);
	}
	printf("%d\n", szz(ans));
	for(int e : ans) printf("%d ", e); puts("");
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}