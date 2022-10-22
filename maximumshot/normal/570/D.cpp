#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

int n, m, timer = 0;
vec< vec< int > > g;
vec< int > in, out, h;
vec< vec< int > > mas;
vec< vec< vec<int > > > cnt;
string s;

void read() {
    scanf("%d %d", &n, &m);
    g.resize(n + 1);
    for(int x, i = 2;i <= n;i++) {
        scanf("%d", &x);
        g[i].push_back(x);
        g[x].push_back(i);
    }
    cin >> s;
    s = " " + s;
}

void dfs(int v, int p = -1, int H = 1) {
    in[v] = timer++;
    h[v] = H;
    mas[H].push_back(v);
    for(int i = 0;i < (int)g[v].size();i++) {
        int to = g[v][i];
        if(to != p) dfs(to, v, H + 1);
    }
    out[v] = timer++;
}

bool cmp(int p1, int p2) {
    return (in[p1] < in[p2]);
}

void prepare() {
    in.resize(n + 1);
    out.resize(n + 1);
    h.resize(n + 1);
    mas.resize(n + 1);
    dfs(1);
    for(int i = 0;i <= n;i++) {
        if(mas[i].empty()) continue;
        sort(ALL(mas[i]), cmp);
    }

    cnt.resize(n + 1);
    for(int i = 0;i <= n;i++) {
        int sz = (int)mas[i].size();
        if(sz == 0) continue;
        cnt[i].resize(sz, vec< int >(26, 0));
        for(int j = 0;j < sz;j++) {
            if(j > 0) cnt[i][j] = cnt[i][j - 1];
            int symb = s[mas[i][j]] - 'a';
            cnt[i][j][symb]++;
        }
    }
}

bool check(int v, int high) {

    if(mas[high].empty()) return 1;

    // [ in[v] .. out[v] ]

    int bl, br, bm, l, r;

    bl = 0, br = (int)mas[high].size() - 1;

    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(in[mas[high][bm]] < in[v]) bl = bm + 1;
        else br = bm;
    }

    if(in[mas[high][bl]] >= in[v]) l = bl;
    else if(in[mas[high][br]] >= in[v]) l = br;
    else return 1;

    bl = 0, br = (int)mas[high].size() - 1;

    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(in[mas[high][bm]] > out[v]) br = bm - 1;
        else bl = bm;
    }

    if(in[mas[high][br]] <= out[v]) r = br;
    else if(in[mas[high][bl]] <= out[v]) r = bl;
    else return 1;

    // [l .. r]

    int CC = 0;

    for(int i = 0;i < 26;i++) {
        int cc = cnt[high][r][i] - (l?cnt[high][l - 1][i] : 0);
        if(cc % 2) CC++;
    }

    return (CC <= 1);
}

bool solve() {
   
    read();
    prepare();

    int v, high;

    while(m--) {
        scanf("%d %d", &v, &high);
        puts(check(v, high)?"Yes" : "No");
    }
    
    return true;
}

int main() {

    //while(solve());
    solve();    

    return 0;
}