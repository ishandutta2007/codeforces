
#include<stdio.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<cstring>
#include<time.h>
#include<stack>
#include<complex>
#include<set>

#pragma warning (disable: 4996)

#define mp make_pair
#define ll long long int

using namespace std;

ll n,k,q,a[200005];
map<ll, ll> m;
map<ll, ll>::iterator it;

void solve() {
	ll i, j,t,x;
	for (i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
	}
	for (i = 0; i < q; i++) {
		scanf("%I64d%I64d", &t,&x);
		x--;
		if (t == 1) {
			if (m.size() < k) {
				m[a[x]] = x+1;
			}
			else {
				if (m.begin()->first < a[x]) {
					m.erase(m.begin());
					m[a[x]] = x+1;
				}
			}
		}
		else {
			t = 0;
			for (it = m.begin(); it != m.end(); it++) {
				if (it->second == x + 1) {
					t = 1;
				}
			}
			if (t == 1) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	scanf("%I64d%I64d%I64d", &n,&k,&q);
	solve();
	return 0;
}