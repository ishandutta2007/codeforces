#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int N;
string get_s(pii x) {
	string res;
	res.pb('a' + x.Fi);
	res.pb('0' + x.Se + 1);
	return res;
}

typedef pair<pii, int> ppi;
vector <ppi> L;

void output() {
	int n = szz(L);
	vector <string> ans;
	for(auto e : L) {
		if(e.Se == 0 && n > N + 1) {
			--n;
		}
		else ans.pb(get_s(e.Fi));
	}
	for(string e : ans) printf("%s ", e.c_str()); puts("");
}

int main() {
	scanf("%d", &N);
	if(N <= 14) {
		L.pb(ppi(pii(0, 0), 1));
		for(int i=1;i<8;i++) L.pb(ppi(pii(0, i), (i==7?1:0)));
		for(int i=1;i<8;i++) L.pb(ppi(pii(i, 7), (i==7?1:0)));
		output();
	}
	else if(N >= 40) {
		for(int i=0;i<6;i++) {
			if(i % 2 == 0) {
				for(int j=0;j<8;j++) L.pb(ppi(pii(i, j), (j==0||j==7) ? 1 : 0));
			}
			else {
				for(int j=7;j>=0;j--) L.pb(ppi(pii(i, j), (j==0||j==7) ? 1 : 0));
			}
		}
		for(int j=0;j<8;j++) {
			if(j % 2 == 0) L.pb(ppi(pii(7, j), 1)), L.pb(ppi(pii(6, j), 1));
			else L.pb(ppi(pii(6, j), 1)), L.pb(ppi(pii(7, j), 1));
		}
		output();
	}
	else {
		for(int i=0;i<6;i++) {
			if(i % 2 == 0) {
				for(int j=0;j<8;j++) L.pb(ppi(pii(i, j), (j==0||j==7) ? 1 : 0));
			}
			else {
				for(int j=7;j>=0;j--) L.pb(ppi(pii(i, j), (j==0||j==7) ? 1 : 0));
			}
		}
		L.pb(ppi(pii(7, 0), 1));
		L.pb(ppi(pii(7, 7), 1));
		output();
	}
	return 0;
}