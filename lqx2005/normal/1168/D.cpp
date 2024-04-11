#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define par pair<int, int>
using namespace std;
typedef long long ll;
const int N = 1.5e5 + 10;
struct node {
    int cnt[26], tot;
    node() {memset(cnt, 0, sizeof(cnt)), tot = 0; }
    friend node operator + (node a, char b) {
		if(b != '?') a.cnt[b - 'a']++;
		a.tot++;
        return a;
    }
    friend node operator - (node a, char b) {
		if(b != '?') a.cnt[b - 'a']--;
		a.tot--;
        return a;
    }
    friend node operator + (const node a, const node b) {
        node c;
		for(int i = 0; i < 26; i++) c.cnt[i] = max(a.cnt[i], b.cnt[i]);
		c.tot = max(a.tot, b.tot);
        return c;
    }
	friend node operator * (const node a, const node b) {
		node c;
		for(int i = 0; i < 26; i++) c.cnt[i] = a.cnt[i] + b.cnt[i];
		c.tot = a.tot + b.tot;
		return c;
	}
	int sum() {
		int sum = 0;
		for(int i = 0; i < 26; i++) sum += cnt[i];
		return sum;
	}
}val[N], info[N];
int mn[N];
int n, q, dep[N], id[N], fa[N], lea[N];
vector<int> e[N];
char op[N];
void upd(int p) {
	if(sz(e[p]) == 0) info[p] = val[p], mn[p] = 0;
	else {
		info[p] = info[e[p][0]] + info[e[p][1]];
		mn[p] = min(min(mn[e[p][0]], mn[e[p][1]]), info[p].tot - info[p].sum());
		info[p] = info[p] * val[p];
	}
	return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
	for(int i = 1; i <= n; i++) lea[i] = 0;
    for(int i = 2; i <= n; i++) {
        cin >> fa[i] >> op[i];
		lea[fa[i]]++;
        dep[i] = dep[fa[i]] + 1;
    }
    vector<int> l;
    for(int i = 2; i <= n; i++) if(!lea[i]) l.push_back(i);
	id[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(lea[i] == 0 || lea[i] == 2) {
            for(int x = i; !id[x]; id[x] = i, val[i] = val[i] + op[x], fa[i] = x = fa[x]);
        }
    }
    int neq = 0;
    for(int i = 1; i < sz(l); i++) if(dep[l[i - 1]] != dep[l[i]]) neq = 1;
    for(int i = 1; i <= n; i++) if(id[i] == i && fa[i]) e[fa[i]].push_back(i);
	int rt = -1;
    for(int i = n; i >= 1; i--) {
		if(id[i] == i) {
			rt = i;
			upd(i);
		}
	}
    for(int i = 1; i <= q; i++) {
        int x;
        char opt;
        cin >> x >> opt;
		if(neq) {
			cout << "Fou" << endl;
			continue;
		}
        val[id[x]] = val[id[x]] - op[x];
		op[x] = opt;
		val[id[x]] = val[id[x]] + op[x];
		for(int y = id[x]; y; upd(y), y = fa[y]);
		if(mn[rt] < 0) {
			cout << "Fou" << endl;
		} else {
			int s = info[rt].tot - info[rt].sum(), ans = 0;
			for(int j = 0; j < 26; j++) {
				ans += (s + info[rt].cnt[j]) * (j + 1);
			}
			cout << "Shi" << " " << ans << endl;
		}
    }
    return 0;
}