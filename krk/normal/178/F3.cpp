#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;
const int Maxn = 2005;

struct trie {
    trie *ch[Maxl];
    int cnt, en;
    trie() {
        for (int i = 0; i < Maxl; i++)
            ch[i] = nullptr;
        cnt = en = 0;
    }
};

int n, k;
string S[Maxn];
trie *tr;

void Insert(trie *tr, const string &s, int lvl)
{
    tr->cnt++;
    if (lvl >= s.length()) { tr->en++; return; }
    int ind = s[lvl] - 'a';
    if (!tr->ch[ind]) tr->ch[ind] = new trie();
    Insert(tr->ch[ind], s, lvl + 1);
}

vector <int> Solve(trie *tr, int len)
{
    vector <int> res(tr->cnt + 1, 0);
    int sz = tr->en;
    for (int i = 1; i <= sz; i++)
        res[i] = i * (i - 1) / 2ll * len;
    for (int i = 0; i < Maxl; i++) if (tr->ch[i]) {
        vector <int> dpu = Solve(tr->ch[i], len + 1);
        int add = tr->ch[i]->cnt;
        for (int j = sz; j >= 0; j--)
            for (int k = 1; k <= add; k++)
                res[j + k] = max(res[j + k], res[j] + dpu[k] + j * k * len);
        sz += add;
    }
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    tr = new trie();
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> S[i];
        Insert(tr, S[i], 0);
    }
    cout << Solve(tr, 0)[k] << endl;
    return 0;
}