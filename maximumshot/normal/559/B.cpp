#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <cstring>

//#include <conio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

const int NMAX = 200200;
const int ALPHSIZE = 26;

int nxt[NMAX][ALPHSIZE];
bool leaf[NMAX];
int sz;

void free() {
    for(int i(0);i < NMAX;i++) {
        leaf[i] = 0;
        for(int j(0);j < ALPHSIZE;j++)
            nxt[i][i] = -1;
    }
    sz = 1;
}

void addString(const string & s, int l, int r) {
    int v = 0;
    for(int i = l;i <= r;i++) {
        int c = s[i] - 'a';
        if(nxt[v][c] == -1) {
            nxt[v][c] = sz++;
        }
        v = nxt[v][c];
    }
    leaf[v] = 1;
}

bool check(const string & s, int l, int r) {
    int v = 0;
    for(int i = l;i <= r;i++) {
        int c = s[i] - 'a';
        if(nxt[v][c] == -1) return 0;
        v = nxt[v][c];
    }
    return leaf[v];
}

void update(string & s, int l, int r) {
    if((r - l + 1) % 2) return;
    string x, y;
    x = y = "";
    int m = (l + r) / 2;
    for(int i(l);i <= m;i++) x += s[i];
    for(int i(m + 1);i <= r;i++) y += s[i];
    if(x > y) swap(x, y);
    for(int j = 0, i = l;i <= m;i++, j++) s[i] = x[j];
    for(int j = 0, i = m + 1;i <= r;i++, j++) s[i] = y[j];
    update(s, l, m);
    update(s, m + 1, r);
}

string a, b;
int n;

bool sol(int l1, int r1, int l2, int r2) {
    if((r1 - l1 + 1) % 2) {
        for(int i = 0;i < (r1 - l1 + 1);i++) {
            if(a[l1 + i] != b[l2 + i]) return 0;
        }
        return 1;
    }

    int m1, m2;
    m1 = (l1 + r1) / 2;
    m2 = (l2 + r2) / 2;

    if(sol(l1, m1, l2, m2) && sol(m1 + 1, r1, m2 + 1, r2)) return 1;
    if(sol(l1, m1, m2 + 1, r2) && sol(m1 + 1, r1, l2, m2)) return 1;
    return 0;
}

bool solve()
{   
    cin >> a >> b;
    n = (int)a.size();
    
    puts(sol(0, n - 1, 0, n - 1)?"YES" : "NO");

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}