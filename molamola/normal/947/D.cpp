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

int S[100010], T[100010];
char buf[100010];
int N, M;
int sum_s[100010], sum_t[100010];
int sum_sa[100010], sum_ta[100010];

void solve(){
	scanf("%s", buf+1);
	N = (int)strlen(buf + 1);
	for(int i=1;i<=N;i++) S[i] = (buf[i] != 'A');
	scanf("%s", buf+1);
	M = (int)strlen(buf+1);
	for(int i=1;i<=M;i++) T[i] = (buf[i] != 'A');
	
	for(int i=1;i<=N;i++) sum_s[i] = sum_s[i-1] + S[i];
	for(int i=1;i<=M;i++) sum_t[i] = sum_t[i-1] + T[i];
	
	for(int i=1;i<=N;i++) {
		if(S[i] == 0) sum_sa[i] = sum_sa[i-1] + 1;
		else sum_sa[i] = 0;
	}
	for(int i=1;i<=M;i++) {
		if(T[i] == 0) sum_ta[i] = sum_ta[i-1] + 1;
		else sum_ta[i] = 0;
	}
	
	int q; scanf("%d", &q);
	while(q--) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		int len_s = b - a + 1;
		int len_t = d - c + 1;
		int last_sa = min(sum_sa[b], len_s);
		int last_ta = min(sum_ta[d], len_t);
		int cnt_s = sum_s[b] - sum_s[a-1];
		int cnt_t = sum_t[d] - sum_t[c-1];
		int ans = 1;
		if(cnt_s == 0 && cnt_t != 0) {
			if(last_sa - 1 < last_ta) ans = 0;
			last_sa = last_ta;
			cnt_s += 2;
		}
		if(last_sa < last_ta) ans = 0;
		else {
			int del = (last_sa - last_ta) % 3;
			if(del != 0) cnt_s += 2;
		}
		if(cnt_s > cnt_t || (cnt_t - cnt_s) % 2 != 0) ans = 0;
		printf("%d", ans);
	} puts("");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}