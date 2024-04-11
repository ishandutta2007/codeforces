#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 7;
const int Maxm = 8;
const int Maxk = 10;
const int Maxd = 4;
const int MaxN = 2 * Maxk + Maxd + 2;
const string lets = "BRWY";

char tmp[Maxm + 2];
int B[Maxn][Maxm];
ii orig[Maxk];
int id[Maxd][Maxd];
int s = 0, t = MaxN - 1;
int R[MaxN][MaxN];
vector <int> neigh[MaxN];
int tk[Maxn][Maxm];
int tkind;
bool gotbest[Maxn * Maxm];
vector <ii> bytk[Maxn * Maxm];
bool vis[MaxN];
int par[MaxN];
int visseq[MaxN];
int vlen;
iii seq[1000000];
int slen;
int gres = -1;
char toprint[2 * Maxn][2 * Maxm];
vector <int> fromL[Maxk], fromR[Maxd];
vector <int> gotnone;

void addEdge(int a, int b, int cap)
{
    R[a][b] = cap;
    neigh[a].push_back(b);
    neigh[b].push_back(a);
}

void removeUpdate(int from, int to, int delt)
{
    R[from][to] -= delt;
}

void addUpdate(int from, int to, int delt)
{
    R[from][to] += delt;
    seq[slen++] = iii(ii(from, to), delt);
}

void Send(int from, int to)
{
    addUpdate(from, to, -1);
    addUpdate(to, from, 1);
}

void Undo(int sz)
{
    while (slen > sz) {
        slen--;
        removeUpdate(seq[slen].first.first, seq[slen].first.second, seq[slen].second);
    }
}

bool getFlow()
{
    for (int i = 0; i < vlen; i++)
        vis[visseq[i]] = false;
    vlen = 0;
    visseq[vlen++] = 0; vis[0] = true;
    for (int i = 0; i < vlen && !vis[MaxN - 1]; i++) {
        int v = visseq[i];
        for (int j = 0; j < neigh[v].size() && !vis[MaxN - 1]; j++) {
            int u = neigh[v][j];
            if (R[v][u] > 0 && !vis[u]) {
                vis[u] = true;
                par[u] = v;
                visseq[vlen++] = u;
            }
        }
    }
    int v = MaxN - 1;
    if (!vis[v]) return false;
    while (v) {
        int u = par[v];
        Send(u, v);
        v = u;
    }
    return true;
}

bool getBest(int ind, int &res)
{
    int rig = 1 + Maxk + Maxd + ind;
    if (R[rig][MaxN - 1] > 0) { addUpdate(rig, MaxN - 1, -1); res += 2; return true; }
    if (R[MaxN - 1][rig] == 0) return false;
    Send(MaxN - 1, rig);
    int mid = -1;
    for (int i = int(neigh[rig].size()) - 1; i >= 0; i--) {
        mid = neigh[rig][i];
        if (R[rig][mid] > 0) { Send(rig, mid); break; }
    }
    assert(mid != -1);
    int lef = -1;
    for (int i = int(neigh[mid].size()) - 1; i >= 0; i--) {
        lef = neigh[mid][i];
        if (R[mid][lef] > 0) { Send(mid, lef); break; }
    }
    assert(lef != -1);
    Send(lef, 0);
    res++;
    addUpdate(rig, MaxN - 1, -1);
    if (getFlow()) res++; 
    return true;
}

void Write(const ii &a, const ii &b, int ind)
{
    ii o = orig[ind];
    if (int(B[a.first][a.second] == o.second) + int(B[b.first][b.second] == o.first) >
        int(B[a.first][a.second] == o.first) + int(B[b.first][b.second] == o.second))
        swap(o.first, o.second);
    toprint[2 * a.first][2 * a.second] = lets[o.first];
    toprint[2 * b.first][2 * b.second] = lets[o.second];
    if (a.first == b.first) toprint[2 * a.first][2 * a.second + 1] = '-';
    else toprint[2 * a.first + 1][2 * a.second] = '|';
}

void Construct()
{
    fill((char*)toprint, (char*)toprint + (2 * Maxn) * (2 * Maxm), '.');
    for (int i = 1; i <= tkind; i++)
        bytk[i].clear();
    for (int i = 0; i < Maxn; i++)
        for (int j = 0; j < Maxm; j++)
            bytk[tk[i][j]].push_back(ii(i, j));
    for (int i = 0; i < Maxk; i++)
        fromL[i].clear();
    for (int i = 0; i < Maxd; i++)
        fromR[i].clear();
    gotnone.clear();
    for (int i = 1; i <= tkind; i++) {
        ii p1 = bytk[i][0];
        ii p2 = bytk[i][1];
        int ind = id[B[p1.first][p1.second]][B[p2.first][p2.second]];        
        if (gotbest[i]) {
            Write(p1, p2, ind);
            continue;
        }
        fromL[ind].push_back(i);
    }
    for (int ind = 0; ind < Maxk; ind++) {
        int bad = R[1 + Maxk + Maxd + ind][MaxN - 1];
        while (gotnone.size() < 28 && bad > 0) {
            gotnone.push_back(ind);
            bad--;
        }
        for (int c = 0; c < Maxd; c++)
            for (int z = 0; z < R[1 + Maxk + Maxd + ind][1 + Maxk + c]; z++)
                fromR[c].push_back(ind);
    }
    for (int ind = 0; ind < Maxk; ind++) {
        for (int c = 0; c < Maxd; c++)
            for (int k = 0; k < R[1 + Maxk + c][1 + ind]; k++) {
                int z = fromL[ind].back(); fromL[ind].pop_back();
                int z2 = fromR[c].back(); fromR[c].pop_back();
                Write(bytk[z][0], bytk[z][1], z2);
            }
        while (!fromL[ind].empty()) {
            int z = fromL[ind].back(); fromL[ind].pop_back();
            int z2 = gotnone.back(); gotnone.pop_back();
            Write(bytk[z][0], bytk[z][1], z2);
        }
    }
}

void Gen(int r, int c, int res)
{
    if (r >= Maxn) {
        if (res > gres) {
            gres = res;
            Construct();
        }
        return;
    }
    if (c >= Maxm) { Gen(r + 1, 0, res); return; }
    if (tk[r][c]) { Gen(r, c + 1, res); return; }
    int ores = res, osz = slen;
    if (c + 2 <= Maxm && !tk[r][c + 1]) {
        tkind++;
        tk[r][c] = tk[r][c + 1] = tkind;
        int ind = id[B[r][c]][B[r][c + 1]];
        if (getBest(ind, res))
            gotbest[tkind] = true;
        else {
            addUpdate(0, 1 + ind, 1);
            if (R[0][1 + ind] == 1 && getFlow()) res++;
        }
        Gen(r, c + 2, res);
        res = ores;
        Undo(osz);
        gotbest[tkind] = false;
        tkind--;
        tk[r][c] = tk[r][c + 1] = false;
    }
    if (r + 2 <= Maxn && !tk[r + 1][c]) {
        tkind++;
        tk[r][c] = tk[r + 1][c] = tkind;
        int ind = id[B[r][c]][B[r + 1][c]];
        if (getBest(ind, res))
            gotbest[tkind] = true;
        else {
            addUpdate(0, 1 + ind, 1);
            if (R[0][1 + ind] == 1 && getFlow()) res++;
        }
        Gen(r, c + 1, res);
        res = ores;
        Undo(osz);
        gotbest[tkind] = false;
        tkind--;
        tk[r][c] = tk[r + 1][c] = false;
    }
}

int main()
{
    for (int i = 0; i < Maxn; i++) {
        scanf("%s", tmp);
        for (int j = 0; j < Maxm; j++)
            B[i][j] = lets.find(tmp[j]);
    }
    int pnt = 0;
    for (int i = 0; i < Maxd; i++)
        for (int j = Maxd - 1; j >= i; j--) {
            id[i][j] = id[j][i] = pnt;
            orig[pnt] = ii(i, j);
            addEdge(1 + pnt, 1 + Maxk + i, 28);
            addEdge(1 + Maxk + i, 1 + Maxk + Maxd + pnt, 28);
            if (i != j) {
                addEdge(1 + pnt, 1 + Maxk + j, 28);
                addEdge(1 + Maxk + j, 1 + Maxk + Maxd + pnt, 28);
            }
            pnt++;
        }
    for (int i = 0; i < Maxk; i++) {
        addEdge(0, 1 + i, 0);
        addEdge(1 + Maxk + Maxd + i, MaxN - 1, 0);
    }
    for (int i = 0; i < Maxk; i++)
        scanf("%d", &R[1 + Maxk + Maxd + i][MaxN - 1]);
    for (int i = 0; i < MaxN; i++)
        sort(neigh[i].rbegin(), neigh[i].rend());
    Gen(0, 0, 0);
    cout << gres << endl;
    for (int i = 0; i < 13; i++) {
        toprint[i][15] = '\0';
        printf("%s\n", toprint[i]);
    }
    return 0;
}