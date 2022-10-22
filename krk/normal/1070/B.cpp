#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef pair <uint, int> ui;

const int Maxb = 32;

struct trie {
    bool myblack, mywhite;
    bool hasblack, haswhite;
    trie *ch[2];
    trie() { myblack = mywhite = hasblack = haswhite = false; ch[0] = ch[1] = NULL; }
};

int n;
char tmp[50];
trie *tr;
bool fall;
vector <ui> res;

void Insert(trie *tr, uint num, int lvl, int lim, bool white)
{
    if (white) tr->haswhite = true;
    else tr->hasblack = true;
    if (lvl < lim) {
        if (white) tr->mywhite = true;
        else tr->myblack = true;
    } else {
        int ind = bool(num & uint(1) << uint(lvl));
        if (!tr->ch[ind]) tr->ch[ind] = new trie();
        Insert(tr->ch[ind], num, lvl - 1, lim, white);
    }
}

void Solve(trie *tr, uint num, int lvl)
{
    if (!tr->hasblack) return;
    if (!tr->haswhite) { res.push_back(ui(num, 32 - (lvl + 1))); return; }
    if (tr->myblack || tr->mywhite) { fall = true; return; }
    if (tr->ch[0]) Solve(tr->ch[0], num, lvl - 1);
    if (tr->ch[1]) Solve(tr->ch[1], (num | uint(1) << uint(lvl)), lvl - 1);
}

ui Get(const string &s)
{
    uint res = 0;
    int pnt = 0;
    for (int i = 0; i < 4; i++) {
        uint my = 0;
        while (pnt < s.length() && isdigit(s[pnt])) {
            my = uint(10) * my + uint(s[pnt] - '0');
            pnt++;
        }
        pnt++;
        res = res << uint(8) | my;
    }
    int x = 32;
    if (pnt < s.length()) {
        x = 0;
        while (pnt < s.length()) {
            x = 10 * x + int(s[pnt] - '0');
            pnt++;
        }
    }
    return ui(res, x);
}

void getString(uint num, int mask)
{
    uint tk = ((1 << 8) - 1);
    for (int i = 24; i >= 0; i -= 8) {
        uint got = (num >> uint(i)) & uint(tk);
        printf("%d%c", int(got), i == 0? '/': '.');
    }
    printf("%d\n", mask);
}

int main()
{
    scanf("%d", &n);
    tr = new trie();
    while (n--) {
        scanf("%s", tmp);
        bool white = tmp[0] == '+';
        ui my = Get(tmp + 1);
        Insert(tr, my.first, Maxb - 1, 32 - my.second, white);
    }
    Solve(tr, 0, Maxb - 1);
    if (fall) printf("-1\n");
    else {
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            getString(res[i].first, res[i].second);
    }
    return 0;
}