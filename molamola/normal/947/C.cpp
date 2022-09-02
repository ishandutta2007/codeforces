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
typedef pair<double, double> pdd;

int Trie[10000020][2];
int tz, N;
int A[300030], B[300030];
int X[10000010];

void solve(){
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%d", A+i);
	for(int i=1;i<=N;i++) scanf("%d", B+i);
	for(int i=1;i<=N;i++) {
		int now = 0;
		for(int j=29;j>=0;j--) {
			int c = !!(1<<j & B[i]);
			if(Trie[now][c] == 0) Trie[now][c] = ++tz;
			now = Trie[now][c];
			X[now]++;
		}
	}
	for(int i=1;i<=N;i++) {
		int now = 0;
		int ans = 0;
		for(int j=29;j>=0;j--) {
			int c = !!(1<<j & A[i]);
			if(Trie[now][c] != 0 && X[Trie[now][c]] > 0);
			else {
				c ^= 1;
				ans |= 1<<j;
			}
			now = Trie[now][c];
			X[now]--;
		}
		printf("%d ", ans);
	} puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}