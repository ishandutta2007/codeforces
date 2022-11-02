#include <bits/stdc++.h>

using namespace std;

#define PRINTFI64 false

typedef long long ll;

struct SA {

    struct Node {
        int len, link, nxt[26], dp;
        vector<int> chd;
    } st[2000100];

    int sze, last;

    void init() {
        sze = last = 0;
        st[0].len = 0;
        st[0].link = -1;
        sze++;
    }

    vector<int> vect;

    void extend(int c) {
        int cur = sze++;
        vect.push_back(cur);
        st[cur].len = st[last].len + 1;

        int p;
        for (p = last; p != -1 && !st[p].nxt[c]; p = st[p].link)
            st[p].nxt[c] = cur;

        if (p == -1) st[cur].link = 0;
        else {
            int q = st[p].nxt[c];
            if (st[p].len + 1 == st[q].len) st[cur].link = q;
            else {
                int clone = sze++;
                st[clone].len = st[p].len + 1;
                st[clone].link = st[q].link;
                for (int i = 0; i < 26; i++) st[clone].nxt[i] = st[q].nxt[i];
                for (; p != -1 && st[p].nxt[c] == q; p = st[p].link)
                    st[p].nxt[c] = clone;
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    void dfs(int cur) {
        for (int i : st[cur].chd) {
            dfs(i);
            st[cur].dp += st[i].dp;
        }
    }

    void godp() {
        for (int i = 0; i < sze; i++)
            if (st[i].link != -1)
                st[st[i].link].chd.push_back(i);

        for (int i : vect) st[i].dp = 1;
        dfs(0);
        //cout << st[0].dp << endl;
    }

    ll compute(char * s, int l, int pd) {
        int cur = 0;
        int matchlen = 0;
        ll ans = 0;
        for (int ii = 0; ii < 2; ii++) {
            int nd = ii ? pd : l;
            for (int i = 0; i < nd; i++) {
                //cout << matchlen << ' ' << st[cur].dp << endl;
                if (matchlen >= l) ans += st[cur].dp;

                int c = s[i] - 'a';
                for (; cur != 0 && !st[cur].nxt[c]; cur = st[cur].link)
                    matchlen = min(matchlen, st[st[cur].link].len);
                cur = st[cur].nxt[c];
                matchlen = min(matchlen + 1, st[cur].len);
                for (; cur != 0 && st[st[cur].link].len >= l; cur = st[cur].link)
                    matchlen = min(matchlen, st[st[cur].link].len);
            }
        }
        return ans;
    }

} sa;

char s[2000100];
int z[2000100];

//find period of string
int doz(int len) {
    int l = -1, r = -1;
    for (int i = 1; i < 2 * len; i++) {
        if (i >= r) {
            l = r = i;
            while (r < 2 * len && s[r] == s[r - l]) r++;
            z[i] = r - l;
        } else {
            int k = z[i - l];
            if (i + k >= r) {
                l = i;
                while (r < 2 * len && s[r] == s[r - l]) r++;
                z[i] = r - l;
            } else z[i] = k;
        }
    }

    for (int i = 1; i < len; i++)
        if (z[i] >= len)
            return i;
    return len;
}

int main() {
    scanf("%s", s);
    int l = strlen(s);
    sa.init();
    for (int i = 0; i < l; i++) sa.extend(s[i] - 'a');
    sa.godp();

    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        l = strlen(s);
        for (int j = 0; j < l; j++) s[j + l] = s[j];
        int pd = doz(l);
        ll ans = sa.compute(s, l, pd);
        if (PRINTFI64) printf("%I64d\n", ans);
        else printf("%lld\n", ans);
    }
}