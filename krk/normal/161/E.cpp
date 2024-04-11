#include <bits/stdc++.h>
using namespace std;

const int Maxd = 10;
const int Maxn = 100000;
const int Maxm = 6;

struct node {
    node *ch[Maxd];
    int mask;
    node() {
        for (int i = 0; i < Maxd; i++)
            ch[i] = nullptr;
        mask = 0;
    }
};

int bits[1 << Maxd];
bool prime[Maxn];
node *tr[Maxm];
int T;
string my;
int res;

void Add(node *tr, int lvl, const string &s)
{
    if (lvl >= s.length()) return;
    int ind = s[lvl] - '0';
    tr->mask |= 1 << ind;
    if (!tr->ch[ind]) tr->ch[ind] = new node();
    Add(tr->ch[ind], lvl + 1, s);
}

bool Collect(vector <node*> &res)
{
    res.resize(my.size());
    for (int i = 1; i < my.size(); i++) {
        res[i] = tr[my.size()];
        if (!res[i]->ch[my[i] - '0']) return false;
        res[i] = res[i]->ch[my[i] - '0'];
    }
    return true;
}

void Gen(vector <node*> &seq, int r, int c)
{
    if (r >= seq.size()) { res++; return; }
    if (c >= seq.size()) { Gen(seq, r + 1, r + 1); return; }
    node *mem1 = seq[r];
    node *mem2 = seq[c];
    int num = seq[r]->mask;
    while (num) {
        int i = bits[(num & -num) - 1];
        if (seq[r]->ch[i] && seq[c]->ch[i]) {
            seq[r] = seq[r]->ch[i];
            if (r != c) seq[c] = seq[c]->ch[i];
            Gen(seq, r, c + 1);
            seq[r] = mem1; seq[c] = mem2;
        }
        num ^= 1 << i;
    }
}

int main()
{
    for (int i = 0; i < 1 << Maxd; i++)
        bits[i] = __builtin_popcount(i);
    for (int i = 1; i < Maxm; i++)
        tr[i] = new node();
    fill(prime + 2, prime + Maxn, true);
    for (int i = 2; i < Maxn; i++) if (prime[i]) {
        stringstream ss; ss << i;
        string s; ss >> s;
        while (s.length() < Maxm) {
            Add(tr[s.length()], 0, s);
            s = "0" + s;
        }
        for (int j = i; j < Maxn; j += i)
            prime[j] = false;
    }
    scanf("%d", &T);
    while (T--) {
        cin >> my;
        vector <node*> seq;
        res = 0;
        if (Collect(seq))
            Gen(seq, 1, 1);
        printf("%d\n", res);
    }
    return 0;
}