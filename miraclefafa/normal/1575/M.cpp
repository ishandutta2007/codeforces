//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 2005;
char s[maxn][maxn];
int nr[maxn][maxn]; // 
ll ans = 0;
int st[maxn];
int sqr(int a) {
	return a * a;
}
vi calc(vi a) {
	auto chk = [&](int i, int j) {
		return a[i] + 1ll * (j - i) * (j - i);
	};
	
	auto ins = [&](int i, int j, int k) {
		ll cur = 1ll * (j - i) * (a[k] + sqr(k) - a[j] - sqr(j)) - 1ll * (k - j) * (a[j] + sqr(j) - a[i] - sqr(i));
		return cur;
	};
	int fr = 0, ed = 0;
	vi res(a.size());
	for (int i = 0; i < a.size(); i++) {
		while (ed - fr >= 2 && ins(st[ed - 2], st[ed - 1], i) <= 0) ed--;
		st[ed++] = i;
		while (ed - fr >= 2 && chk(st[fr + 1], i) <= chk(st[fr], i)) fr++;
		res[i] = chk(st[fr], i);
	}
	return res;
}
void upd(vi a) {
	vi t = calc(a);
	reverse(a.begin(), a.end());
	vi s = calc(a); reverse(s.begin(), s.end());
	for (int i = 0; i < t.size(); i++) {
		chkmin(t[i], s[i]);
		ans += t[i];
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		scanf("%s", s[i]);
		for (int j = 0; j <= m; j++) {
			if (s[i][j] == '0') nr[i][j] = maxn * 2;
			else nr[i][j] = 0;
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			chkmin(nr[i][j], nr[i][j - 1] + 1);
		for (int j = m - 1; j >= 0; j--)
			chkmin(nr[i][j], nr[i][j + 1] + 1);
	}
	for (int j = 0; j <= m; j++) {
		vi cur(n + 1);
		for (int i = 0; i <= n; i++)
			cur[i] = 1ll * nr[i][j] * nr[i][j];
		upd(cur);
	}
	cout << ans << endl;
    return (0-0); //<3
}