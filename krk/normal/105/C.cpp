#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#define mp make_pair
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;
const int Maxk = 1005;

struct weapon {
       string name, clas;
       int atk, def, res, siz;
       vector <int> V;
} W[Maxn];

struct resid {
       string name, type, home;
       int bonus;
} R[Maxk];

int n, k;
bool pl;
int w, wp = -1, a, ap = -1, o, op = -1;

int Find(const string &s)
{
    for (int i = 0; i < n; i++) if (W[i].name == s) return i;
    return -1;
}

int Points(const string &t, const resid &r)
{
    if (t == "weapon" && r.type == "gladiator" ||
        t == "armor" && r.type == "sentry" ||
        t == "orb" && r.type == "physician") return r.bonus;
    return 0;
}

void Build(weapon &w)
{
     priority_queue <ii> Q;
     for (int i = 0; i < k; i++) 
         if (w.name == R[i].home) Q.push(mp(-Points(w.clas, R[i]), i));
     for (int i = 0; i < k; i++)
         if (w.name != R[i].home) {
                    int p = Points(w.clas, R[i]);
                    if (p == 0) continue;
                    if (w.siz > 0) {
                              W[Find(R[i].home)].siz++; w.siz--;
                              R[i].home = w.name;
                              Q.push(mp(-p, i)); 
                    } else if (!Q.empty() && p > -Q.top().first) {
                              R[Q.top().second].home = R[i].home; R[i].home = w.name;
                              Q.pop(); Q.push(mp(-p, i));
                           }
         }
}

void Get(const string &name, vector <int> &V)
{
     V.clear();
     for (int i = 0; i < k; i++) if (name == R[i].home) V.push_back(i);
}

int getPoints(const weapon &w)
{
    int p = w.clas == "weapon"? w.atk: w.clas == "armor"? w.def: w.res;
    for (int i = 0; i < w.V.size(); i++) p += Points(w.clas, R[w.V[i]]);
    return p;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> W[i].name >> W[i].clas >> W[i].atk >> W[i].def >> W[i].res >> W[i].siz;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> R[i].name >> R[i].type >> R[i].bonus >> R[i].home;
        W[Find(R[i].home)].siz--;
    }
    pl = false;
    for (int i = 0; i < n && !pl; i++) pl = W[i].siz > 0;
    for (int i = 0; i < n; i++) if (W[i].clas == "weapon") {
        if (pl) Build(W[i]);
        Get(W[i].name, W[i].V);
        int cand = getPoints(W[i]);
        if (cand > wp) {
                 wp = cand; w = i;
        }
    }
    for (int i = 0; i < n; i++) if (W[i].clas == "armor") {
        if (pl) Build(W[i]);
        Get(W[i].name, W[i].V);
        int cand = getPoints(W[i]);
        if (cand > ap) {
                 ap = cand; a = i;
        }
    }
    for (int i = 0; i < n; i++) if (W[i].clas == "orb") {
        if (pl) Build(W[i]);
        Get(W[i].name, W[i].V);
        int cand = getPoints(W[i]);
        if (cand > op) {
                 op = cand; o = i;
        }
    }
    if (pl) Build(W[w]);
    Get(W[w].name, W[w].V);
    cout << W[w].name << " " << W[w].V.size();
    for (int i = 0; i < W[w].V.size(); i++) cout << " " << R[W[w].V[i]].name;
    cout << endl;
    if (pl) Build(W[a]);
    Get(W[a].name, W[a].V);
    cout << W[a].name << " " << W[a].V.size();
    for (int i = 0; i < W[a].V.size(); i++) cout << " " << R[W[a].V[i]].name;
    cout << endl;
    if (pl) Build(W[o]);
    Get(W[o].name, W[o].V);
    cout << W[o].name << " " << W[o].V.size();
    for (int i = 0; i < W[o].V.size(); i++) cout << " " << R[W[o].V[i]].name;
    cout << endl;
    return 0;
}