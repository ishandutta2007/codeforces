#include <bits/stdc++.h>
using namespace std;

const int Maxn = 415;

string typs;
int n, m;
vector <int> neigh[Maxn];
int val[Maxn];
string s;
char res[Maxn];

int Oth(int x)
{
    return x < n? x + n: x - n;
}

void Traverse(int x, int val[], vector <int> &nw)
{
    if (val[x]) return;
    val[x] = 1;
    nw.push_back(x);
    for (int i = 0; i < neigh[x].size(); i++)
        Traverse(neigh[x][i], val, nw);
}

bool Check(int x)
{
    int nd[Maxn] = {};
    vector <int> dum;
    Traverse(x, nd, dum);
    if (nd[Oth(x)]) val[Oth(x)] = 1;
    fill(nd, nd + Maxn, 0);
    dum.clear();
    Traverse(Oth(x), nd, dum);
    if (nd[x]) val[x] = 1;
    return !val[x] || !val[Oth(x)];
}

void getAny(int x)
{
    if (x >= n) {
        res[n] = '\0';
        printf("%s\n", res);
        return;
    }
    vector <int> dum;
    for (int i = 0; i < typs.length(); i++)
        if (typs[i] == 'C' && !val[Oth(x)] || typs[i] == 'V' && !val[x]) {
            res[x] = i + 'a';
            Traverse(typs[i] == 'C'? x: Oth(x), val, dum);
            getAny(x + 1);
            return;
        }
}

bool getNotSmaller(int x)
{
    if (x >= n) {
        res[n] = '\0';
        printf("%s\n", res);
        return true;
    }
    int ind = s[x] - 'a';
    if (typs[ind] == 'C' && !val[Oth(x)] || typs[ind] == 'V' && !val[x]) {
        res[x] = s[x];
        vector <int> mem;
        Traverse(typs[ind] == 'C'? x: Oth(x), val, mem);
        if (getNotSmaller(x + 1)) return true;
        for (int i = 0; i < mem.size(); i++)
            val[mem[i]] = 0;
        mem.clear();
    }
    vector <int> dum;
    for (int i = ind + 1; i < typs.length(); i++)
        if (typs[i] == 'C' && !val[Oth(x)] || typs[i] == 'V' && !val[x]) {
            res[x] = i + 'a';
            Traverse(typs[i] == 'C'? x: Oth(x), val, dum);
            getAny(x + 1);
            return true;
        }
    return false;
}

int main()
{
    cin >> typs;
    bool sam = true;
    for (int i = 1; i < typs.length() && sam; i++)
        sam = typs[i] == typs[0];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        char va, vb;
        scanf("%d %c %d %c", &a, &va, &b, &vb);
        if (sam && typs[0] == va && typs[0] != vb) {
            printf("-1\n");
            return 0;
        }
        a--; b--;
        if (va == 'V') a += n;
        if (vb == 'V') b += n;
        neigh[a].push_back(b);
        neigh[Oth(b)].push_back(Oth(a));
    }
    for (int i = 0; i < n; i++)
        if (!Check(i)) {
            printf("-1\n");
            return 0;
        }
    cin >> s;
    if (!getNotSmaller(0))
        printf("-1\n");
    return 0;
}