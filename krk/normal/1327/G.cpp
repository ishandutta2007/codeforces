#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int K = 28;

struct Vertex {
    int next[K];
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    ll tot = Inf, my = 0;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s, int add) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].my += add;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

ll getAll(int v)
{
    if (t[v].tot == Inf)
        if (v == 0) t[v].tot = t[v].my;
        else t[v].tot = t[v].my + getAll(get_link(v));
    return t[v].tot;
}

const int Maxk = 1005;
const int Maxn = 1000005;
const int Maxb = 14;

char tmp[Maxn];
int k;
string a[Maxk];
int ac[Maxk];
string s;
vector <int> seq;
ll res;
char nw[30];
int nlen;
vector <ll> dp[1 << Maxb];

void Read(string &s)
{
    scanf("%s", tmp); s = tmp;
}

int main()
{
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        Read(a[i]);
        scanf("%d", &ac[i]);
        add_string(a[i], ac[i]);
    }
    Read(s);
    int cur = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '?') {
            cur = 0;
            seq.push_back(i);
        } else {
            cur = go(cur, s[i]);
            res += getAll(cur);
        }
    t.clear();
    t.push_back(Vertex());
    for (int i = 0; i < k; i++)
        for (int j = 0; j < seq.size(); j++) {
            int st = max((j > 0? seq[j - 1] + 1: 0), seq[j] - int(a[i].length()) + 1);
            for (int z = st; z <= seq[j] && z + int(a[i].length()) <= int(s.length()); z++) {
                int nxtj = j, nlen = 0;
                int l = 0;
                while (l < a[i].length()) {
                    if (s[z + l] == '?') {
                        nw[nlen++] = 'a' + 14 + nxtj;
                        nxtj++;
                        nw[nlen++] = a[i][l];
                    } else if (s[z + l] != a[i][l]) break;
                    l++;
                }
                if (l >= a[i].length()) {
                    nw[nlen] = '\0';
                    add_string(nw, ac[i]);
                }
            }
        }
    int B = seq.size();
    for (int i = 0; i < 1 << Maxb; i++)
        dp[i].resize(t.size(), -Inf);
    dp[0][0] = 0;
    ll res2 = -Inf;
    for (int i = 0; i < 1 << Maxb; i++) {
        int bits = __builtin_popcount(i);
        for (int j = 0; j < t.size(); j++) if (dp[i][j] > -Inf) {
            ll cur = dp[i][j];
            if (bits == B) {
                res2 = max(res2, cur);
                continue;
            }
            int nj = go(j, 'a' + 14 + bits);
            cur += getAll(nj);
            for (int l = 0; l < Maxb; l++) if (!(i & 1 << l)) {
                int nj2 = go(nj, 'a' + l);
                ll cur2 = cur + getAll(nj2);
                dp[i | 1 << l][nj2] = max(dp[i | 1 << l][nj2], cur2);
            }
        }
    }
    res += res2;
    cout << res << endl;
    return 0;
}