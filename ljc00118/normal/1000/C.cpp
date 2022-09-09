#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

const int N = 400005;

ll cnt[N], pre[N];
ll l[N], r[N];
int s[N], f[N], cnt1[N], cnt2[N];
int n, len = 0;

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		read(l[i]); read(r[i]);
		pre[++len] = l[i];
		pre[++len] = r[i];
	}
	sort(pre + 1, pre + len + 1);
	len = unique(pre + 1, pre + len + 1) - pre - 1;
	for(int i = 1; i <= n; i++) {
		l[i] = lower_bound(pre + 1, pre + len + 1, l[i]) - pre;
		r[i] = lower_bound(pre + 1, pre + len + 1, r[i]) - pre;
		s[l[i]]++, s[r[i] + 1]--;
		cnt1[l[i]]++; cnt2[r[i]]++;
	}
	for(int i = 1; i <= len; i++) {
		f[i] = f[i - 1] + s[i];
		cnt[f[i]]++;
		cnt[(f[i] + f[i - 1] - cnt2[i - 1] - cnt1[i]) / 2] += (pre[i] - pre[i - 1] - 1ll);
	}
	for(int i = 1; i <= n; i++) printf("%I64d ", cnt[i]);
	return 0;
}