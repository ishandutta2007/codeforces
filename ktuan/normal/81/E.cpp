#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

PII operator+(PII a, PII b) {
    return MP(a.fi+b.fi,a.se+b.se); 
}

PII operator-(PII a, PII b) {
    return MP(a.fi-b.fi,a.se-b.se); 
}

int n;
int f[100010], s[100010];
VI ke[100010];

int cur, ROOT;

PII F[2][100010][2];
bool dt[2][100010][2];

PII calc(int i, bool b) {
    if(dt[cur][i][b]) return F[cur][i][b];
    dt[cur][i][b] = true;
    PII res = MP(0,0);
    if(!b) {
        Rep(k,ke[i].size()) {
            int j = ke[i][k];
            if(j != ROOT && f[j] == i) {
                res = res + max( calc( j, 0), calc(j, 1));
            }   
        }
    }
    else {
        PII total = MP(0,0);
        Rep(k, ke[i].size()) {
            int j = ke[i][k];
            if(j != ROOT && f[j] == i) {
                total = total + max( calc(j, 0), calc(j, 1));   
            }
        }   
        res = total;
        Rep(k,ke[i].size()) {
            int j = ke[i][k];
            if(j != ROOT && f[j] == i) {
                res = max( res, total - max( calc(j, 0), calc(j, 1)) + calc(j, 0) + MP(1, s[j] != s[i] ? 1 : 0));
            }   
        }
    }
    
//  cout << "calc " << i << " " << b << " " << res.fi << " " << res.se << endl;
    
    return F[cur][i][b] = res;
}

void truy(int i, int b, vector<PII> &v) {
    PII res = calc(i, b);
    if(!b) {
        Rep(k,ke[i].size()) {
            int j = ke[i][k];
            if(j != ROOT && f[j] == i) {
                PII p0 = calc( j, 0);
                PII p1 = calc( j, 1);
                if(p0 > p1) truy( j, 0, v);
                else truy( j, 1, v);
            }   
        }   
    }   
    else {
        PII total = MP(0,0);
        Rep(k, ke[i].size()) {
            int j = ke[i][k];
            if(j != ROOT && f[j] == i) {
                total = total + max( calc(j, 0), calc(j, 1));   
            }
        }
        if(total == res) {
            Rep(k,ke[i].size()) {
                int j = ke[i][k];
                if(j != ROOT && f[j] == i) {
                    PII p0 = calc( j, 0);
                    PII p1 = calc( j, 1);
                    if(p0 > p1) truy( j, 0, v);
                    else truy( j, 1, v);
                }   
            }
        }
        else {
            Rep(k,ke[i].size()) {
                int j = ke[i][k];
                if(j != ROOT && f[j] == i) {
                    PII z = total - max( calc(j, 0), calc(j, 1)) + calc(j, 0) + MP(1, s[j] != s[i] ? 1 : 0);
                    
                    if(z == res) {
                        
                        v.pb(MP(i,j));
                        
                        Rep(t,ke[i].size()) {
                            int j = ke[i][t];
                            if(j != ROOT && f[j] == i) {
                                if(t == k) truy( j, 0, v);
                                else {
                                    PII p0 = calc( j, 0);
                                    PII p1 = calc( j, 1);
                                    if(p0 > p1) truy( j, 0, v);
                                    else truy( j, 1, v);
                                }   
                            }   
                        }
                        
                        break;  
                    }
                }
            }
        }   
    }
}

void solve(int root, PII &p, vector<PII> &v) {
    ROOT = root;
    PII p0 = calc(root, 0);
    PII p1 = calc(root, 1);
    if(p0 > p1) {
        p = p0;
        truy( root, 0, v);  
    }
    else {
        p = p1;
        truy( root, 1, v);
    }
}

bool mark[100010];

bool vs[100010];

void dfs(int i) {
    vs[i] = true;
    Rep(k,ke[i].size()) {
        int j = ke[i][k];
        if(!vs[j]) dfs(j);  
    }   
}

void process(int si, PII &p, vector<PII> &v) {
    // fill vs
    
    dfs(si);
    
    // tim goc
    int tr = -1;
    while(!mark[si]) {
        mark[si] = true;
        tr = si;
        si = f[si]; 
    }
    
    PII p1, p2;
    vector<PII> v1, v2;
    
//  cout << tr << " " << si << endl;

    cur = 1 - cur;
    solve( tr, p1, v1);
    
    p = p1; v = v1;
//  cout << "here: " << p1.fi << " " << p1.se << endl;
    
//  return;
    

    cur = 1 - cur;
    solve( si, p2, v2);
    
//  cout << "here: " << p2.fi << " " << p2.se << endl;

    if(p1 < p2) { p = p2, v = v2; }
    else { p = p1, v = v1; }
}

int main() {
    scanf("%d", &n);
    For(i,1,n) scanf("%d%d", f+i, s+i);
    memset(F,-1,sizeof(F));
    
    For(i,1,n) {
        if(f[f[i]] != i) ke[i].pb(f[i]), ke[f[i]].pb(i);
    }
    For(i,1,n) {
        if(f[f[i]] == i) ke[i].pb(f[i]);
    }
    
    PII res = MP(0,0);
    vector<PII> vr;
    
    For(i,1,n) if(!vs[i]) {
        PII p;
        vector<PII> v;
        process(i, p, v);   
//      cout << p.fi << " " << p.se << endl;
        res = res + p;
        Rep(j,v.size()) vr.pb(v[j]);
//      break;
    }
    
    printf("%d %d\n", res.fi, res.se);
    Rep(i,vr.size()) {
        printf("%d %d\n", vr[i].fi, vr[i].se);  
    }
    
    return 0;
}