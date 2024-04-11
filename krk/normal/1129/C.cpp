#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct trie *ptrie;

const int Maxd = 10;
const int mod = 1000000007;

struct trie {
    trie *ch[2];
    int dp[Maxd];
    trie() {
        ch[0] = ch[1] = NULL;
        fill(dp, dp + Maxd, 0);
    }
};

int getNext(int v, int symb)
{
    if (v == 0)
        return symb == 0? 1: 4;
    if (v == 1)
        return symb == 0? 2: 3;
    if (v == 2)
        return symb == 0? 7: 8;
    if (v == 3)
        return symb == 0? 8: 7;
    if (v == 4)
        return symb == 0? 5: 6;
    if (v == 5)
        return 7;
    if (v == 6)
        return symb == 0? 7: 9;
    if (v == 7)
        return 0;
    if (v == 8)
        return symb == 0? 0: -1;
    if (v == 9) return -1;
}

vector <ptrie> seq;
ptrie tr;
int m;
int res;

int main()
{
    tr = new trie();
    tr->dp[0] = 1;
    scanf("%d", &m);
    while (m--) {
        int a; scanf("%d", &a);
        seq.push_back(tr);
        for (int i = 0; i < seq.size(); i++) {
            if (!seq[i]->ch[a]) {
                ptrie nw = new trie();
                for (int j = 0; j < Maxd; j++) {
                    int nxt = getNext(j, a);
                    if (nxt != -1) {
                        nw->dp[0] = (nw->dp[0] + seq[i]->dp[j]) % mod;
                        if (nxt != 0)
                            nw->dp[nxt] = (nw->dp[nxt] + seq[i]->dp[j]) % mod;
                    }
                }
                res = (res + nw->dp[0]) % mod;
                seq[i]->ch[a] = nw;
            }
            seq[i] = seq[i]->ch[a];
        }
        printf("%d\n", res);
    }
    return 0;
}