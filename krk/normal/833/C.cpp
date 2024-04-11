#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxk = 30;
const int Maxz = 20;
const int Maxd = 10;
const int Maxn = 4686830;

ll C[Maxk][Maxk];
int nxt[Maxn][9];
bool was[Maxn];
bool an[Maxz][Maxn];
string L;
string R;

void Gen(int lftn, int lftk, int othn, int othk, int val1, int val2, int wh)
{
    if (othk > othn) return;
    if (othk == 0) {
        if (wh) nxt[val1][wh - 1] = val2; 
        return; 
    }
    Gen(lftn - 1, lftk - 1, othn - 1, othk - 1, val1, val2, wh);
    Gen(lftn - 1, lftk, othn - 1, othk, val1 + C[lftn - 1][lftk - 1], val2 + C[othn - 1][othk - 1], wh);
    if (wh == 0) {
        wh = Maxd - lftk;
        Gen(lftn - 1, lftk - 1, othn - 2, othk - 1, val1, val2 + C[othn - 1][othk - 1], wh);
    }
}

int Nxt(int val, int wh) { return wh == 0? val: nxt[val][wh - 1]; }

void genAny(int lft, int val, int from = 0)
{
    if (an[lft][val]) return;
    an[lft][val] = true;
    if (lft == 0) was[val] = true;
    else {
        while (from < Maxd && an[lft - 1][Nxt(val, from)])
            from++;
        if (from >= Maxd) return;
        for (int i = from; i < Maxd; i++)
            genAny(lft - 1, Nxt(val, i), from);
    }
}

void genR(int ind, int val)
{
    if (ind >= R.length()) was[val] = true;
    else {
        int rig = R[ind] - '0';
        for (int i = 0; i < rig; i++)
            genAny(int(R.length()) - 1 - ind, Nxt(val, i));
        genR(ind + 1, Nxt(val, rig));
    }
}

void genL(int ind, int val)
{
    if (ind >= L.length()) was[val] = true;
    else {
        int lef = L[ind] - '0';
        genL(ind + 1, Nxt(val, lef));
        for (int i = lef + 1; i < Maxd; i++)
            genAny(int(L.length()) - 1 - ind, Nxt(val, i));
    }
}

void genLR(int ind, int val)
{
    if (ind >= R.length()) was[val] = true;
    else {
        int lef = L[ind] - '0', rig = R[ind] - '0';
        if (lef == rig) {
            genLR(ind + 1, Nxt(val, lef));
            return;
        }
        genL(ind + 1, Nxt(val, lef));
        genR(ind + 1, Nxt(val, rig));
        for (int i = lef + 1; i < rig; i++)
            genAny(int(R.length()) - 1 - ind, Nxt(val, i));
    }
}

int main()
{
    for (int i = 0; i < Maxk; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    Gen(27, 9, 27, 9, 0, 0, 0);
    cin >> L;
    cin >> R;
    while (L.length() < R.length())
        L = "0" + L;
    genLR(0, 0);
    int res = 0;
    for (int i = 0; i < Maxn; i++)
        if (was[i]) res++;
    cout << res << endl;
    return 0;
}