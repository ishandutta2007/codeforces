#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10, T = 1 << 20;
int k, n, m;
int l[N], r[N], p[20];
int opt1[N], opt2[N];
int mn[T], mx[T], cnt[T];

int chkmin(int &x, int y) {
	if(x >= y) return x = y, 1;
	return 0;
}

int change(int msk, int a, int b) {
    int x = (msk >> a ) & 1, y = (msk >> b) & 1;
    msk &= (~ ((1 << a) | (1 << b)));
    msk = msk | (x << b) | (y << a);
    return msk;
}

int main() {
    memset(mx, 0xc0, sizeof(mx));
    memset(mn, 0x3f, sizeof(mn));
    for(int i = 1; i < T; i++) cnt[i] = cnt[i >> 1] + (i & 1);
    cin >> n >> m >> k;
    int str = 0, ed = 0;
    string s, t;
    cin >> s >> t;
    int s1 = 0, t1 = 0;
    for(int i = 0; i < k; i++) {
    	p[i] = i;
        str = str | (s[i] - '0') << i;
        s1 += s[i] - '0';
    }
    for(int i = 0; i < k; i++) {
        ed = ed | (t[i] - '0') << i;
        t1 += t[i] - '0';
    }
    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }
    opt1[0] = str, opt2[0] = ed;
    for(int i = 1; i <= n; i++) {
        opt1[i] = change(opt1[i - 1], p[l[i]], p[r[i]]);
        opt2[i] = change(opt2[i - 1], p[l[i]], p[r[i]]);
        swap(p[l[i]], p[r[i]]);
    }
    for(int i = 0; i <= n; i++) {
    	mx[opt2[i]] = max(mx[opt2[i]], i);
    	mn[opt1[i]] = min(mn[opt1[i]], i);
	}
	for(int i = T - 1; i >= 0; i--) {
		for(int j = 0; j < 20; j++) {
			if(!(i >> j & 1)) {
				mx[i] = max(mx[i], mx[i | 1 << j]);
				mn[i] = min(mn[i], mn[i | 1 << j]);
			}
		}
	}
	int ans = - 1, msk = -1;
	for(int i = 0; i < T; i++) {
		if(mn[i] + m > mx[i]) continue;
		int c = cnt[i] + max(k - s1 - t1 + cnt[i], 0);
		if(c > ans) {
			ans = c, msk = i;
		}
	}
	cout << ans << endl;
	cout << mn[msk] + 1 <<" " << mx[msk] << endl;
    return 0;
}