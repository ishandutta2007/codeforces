#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
const int N=1<<17;
pair<int, int> st[2*N];

pair<int, int> getmax(int a, int b) {
	a += N;
	b += N;
	pair<int, int> ma = {0, 0};
	while (a <= b) {
		if (a%2) ma = max(ma, st[a++]);
		if (!(b%2)) ma = max(ma, st[b--]);
		a /= 2;
		b /= 2;
	}
	return ma;
}

int a[101010];
ll dp[101010];


int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i = 1; i < n; i++) {
		cin>>a[i];
	}
	a[n] = n;
	for (int i = 1; i <= n; i++) {
		st[i+N] = {a[i], i};
	}
	for (int i = N-1; i > 0; i--) {
		st[i] = max(st[i*2], st[i*2+1]);
	}
	ll v = 0;
	for (int i = n-1; i >= 1; i--) {
		auto maxA = getmax(i+1, a[i]);
		int to = maxA.S;
		dp[i] = dp[to] + (ll)(n - i) - (ll)(a[i] - to);
		v += dp[i];
	}
	cout<<v<<endl;
}