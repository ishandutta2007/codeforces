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
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ldouble;

deque<int> A[100010], B[100010];
int n, m;
char buf[100010];

vector <pii> ans;

pii Get(int x) {
	return pii(x / m + 1, x % m + 1);
}

void Do(int f, int t) {
	ans.pb(pii(f, t));
	int c = A[f].back(); A[f].pop_back();
	A[t].push_front(c);
}

vector <int> get_b(int x) {
	vector <int> temp;
	for(int e : B[x]) temp.pb(e);
	reverse(all(temp));
	return temp;
}

int cnt[100010];

int find_0() {
	int f = -1;
	for(int a=1;a<m;a++) if(cnt[a]) { f = a; break; }
	cnt[f]--;
	return f;
}

int find_1() {
	int f = -1;
	for(int a=1;a<n;a++) if(cnt[a*m]) { f = a*m; break; }
	cnt[f]--;
	return f;
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, n*m) {
		scanf("%s", buf);
		for(int j=0;buf[j];j++) A[i].pb(buf[j]-'0');
	}
	rep(i,n*m) {
		scanf("%s", buf);
		for(int j=0;buf[j];j++) B[i].pb(buf[j]-'0');
	}
	for(int i=1;i<m;i++) {
		while(szz(A[i])) Do(i, 0);
	}
	for(int i=m;i<m*n;i+=m) {
		while(szz(A[i])) Do(i, 0);
	}
	for(int i=1;i<n;i++) for(int j=1;j<m;j++) {
		int ti = i * m + j;
		while(szz(A[ti])) {
			int t = A[ti].back();
			if(t == 0) Do(ti, j);
			else Do(ti, i*m);
		}
	}
	while(szz(A[0])) {
		int t = A[0].back();
		if(t == 0) Do(0, 1);
		else Do(0, m);
	}
	
	for(int i=1;i<n;i++) for(int j=1;j<m;j++) {
		int ti = i * m + j;
		vector <int> v = get_b(i * m + j);
		for(int e : v) {
			if(e == 0) {
				if(szz(A[j]) == 0) {
					int f = -1;
					for(int a=1;a<m;a++) if(szz(A[a])) { f = a; break; }
					Do(f, j);
				}
				Do(j, ti);
			}
			else {
				if(szz(A[i*m]) == 0) {
					int f = -1;
					for(int a=1;a<n;a++) if(szz(A[a*m])) { f = a; break; }
					Do(f*m, i*m);
				}
				Do(i*m, ti);
			}
		}
	}
	for(int i=1;i<m;i++) cnt[i] = szz(A[i]);
	for(int i=1;i<n;i++) cnt[i*m] = szz(A[i*m]);
	
	for(int i=1;i<m;i++) {
		vector <int> v = get_b(i);
		for(int e : v) {
			if(e == 0) {
				int t1 = find_0();
				Do(t1, 0);
				Do(0, i);
			}
			else {
				int t1 = find_1();
				Do(t1, 0);
				Do(0, i);
			}
		}
	}
	for(int i=1;i<n;i++) {
		vector <int> v = get_b(i*m);
		for(int e : v) {
			if(e == 0) {
				int t1 = find_0();
				Do(t1, 0);
				Do(0, i*m);
			}
			else {
				int t1 = find_1();
				Do(t1, 0);
				Do(0, i*m);
			}
		}
	}
	vector <int> v = get_b(0);
	for(int e : v) {
		if(e == 0) {
			int t1 = find_0();
			Do(t1, 0);
		}
		else {
			int t1 = find_1();
			Do(t1, 0);
		}
	}
	/*
	rep(i, n*m) {
		puts("!!");
		for(int e : A[i]) printf("%d ", e); puts("");
		for(int e : B[i]) printf("%d ", e); puts("");
	}
	 */
	
	printf("%d\n", szz(ans));
	for(pii e : ans) {
		pii t = Get(e.Fi);
		printf("%d %d ", t.Fi, t.Se);
		t = Get(e.Se);
		printf("%d %d\n", t.Fi, t.Se);
	}
	return 0;
}