#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

int m, n;
char a[255][255];

pair<int,int> ds[5000];
int nd;

bool check(int i, int j, int bit) {
    for(int h=0;h<8;++h) if((bit&(1<<h))==0) {
        int x = i + dx[h];
        int y = j + dy[h];
        if(0<=x && x < m && 0 <= y && y < n && a[x][y] == '1') return false;
    }
    return true;
}

bool test(int i, int j, int x, int y, int u, int v) {
    for(int h=0;h<8;++h) {
        int p = i + dx[h];
        int q = j + dy[h];
        if(0 <= p && p < m && 0 <= q && q < n && a[p][q] == '1' && (p < x || p > u || q < y || q > v)) return false;
    }
    return true;
}

bool check2() {
    for(int i=0;i<nd;++i) {
        int x = ds[i].first;
        int y = ds[i].second;
        if(a[x][y] != '1') return false;
    }
    for(int i=0;i<nd;++i) {
        int x = ds[i].first;
        int y = ds[i].second;
        a[x][y] = '2';
    }
    bool ok = true;
    for(int i=0;i<nd;++i) {
        int x = ds[i].first;
        int y = ds[i].second;
        for(int h=0;h<8;++h) {
            int u = x + dx[h];
            int v = y + dy[h];
            if(0 <= u && u < m && 0 <= v && v < n && a[u][v] == '1') ok = false;
        }
    }
    for(int i=0;i<nd;++i) {
        int x = ds[i].first;
        int y = ds[i].second;
        a[x][y] = '1';
    }
    return ok;
}

int main() {
    int st;
    scanf("%d", &st);
    for(int tt=0;tt<st;++tt) {
        scanf("%d%d", &m, &n);
        gets(a[0]);
        for(int i=0;i<m;++i) gets(a[i]);
        int res = 0;
        for(int i=0;i+1<m;++i) {
            for(int j=0;j+1<n;++j) if(a[i][j] == '1' && a[i+1][j] == '1' && a[i][j+1] == '1') {
                if(check( i, j, (1<<3) | (1<<5) | (1<<4))) {
                    // cout << "here" << endl;
                    int u = i;
                    while(u + 1 < m && a[u+1][j] == '1') ++u;
                    int v = j;
                    while(v + 1 < n && a[i][v+1] == '1') ++v;
                    if(v - j == u - i) {
                    bool ok = true;
                    for(int t=i;t<=u;++t) if(a[t][v] != '1') { ok = false; break; }
                    for(int t=j;t<=v;++t) if(a[u][t] != '1') { ok = false; break; }
                    if(!check(i, v, (1<<7) | (1<<5) | (1<<6))) ok = false;
                    if(!check(u, j, (1<<1) | (1<<3) | (1<<2))) ok = false;
                    if(!check(u, v, (1<<7) | (1<<1) | (1<<0))) ok = false;
                    for(int t=i+1;t<u;++t) {
                        if(!test( t, j, i, j, u, v)) ok = false;
                        if(!test( t, v, i, j, u, v)) ok = false;
                    }
                    for(int t=j+1;t<v;++t) {
                        if(!test( i, t, i, j, u, v)) ok = false;
                        if(!test( u, t, i, j, u, v)) ok = false;
                    }
                    nd = 0;
                    for(int t=i;t<=u;++t) ds[nd++] = make_pair( t, j), ds[nd++] = make_pair( t, v);
                    for(int t=j+1;t<v;++t) ds[nd++] = make_pair( i, t), ds[nd++] = make_pair( u, t);
                    if(ok && check2()) ++res;
                    }
                }
            }
        }
        for(int i=0;i+2<m;++i) {
            for(int j=1;j+1<n;++j) {
                if(a[i][j] == '1' && a[i+1][j-1] == '1' && a[i+1][j+1] == '1') {
                    if(check( i, j, (1<<4) | (1<<5) | (1<<6))) {
                        int u1 = i;
                        while(u1 + 1 < m && j-(u1+1)+i >= 0 && a[u1+1][j-(u1+1)+i] == '1') ++u1;
                        int u2 = i;
                        while(u2 + 1 < m && j+(u2+1)-i < n && a[u2+1][j+(u2+1)-i] == '1') ++ u2;
                        if(u1 == u2 && 2 * u1 - i < m) {
                            bool ok = true;
                            int len = u1 - i + 1;
                            int r = 2 * u1 - i;
                            for(int t=0;t<len;++t) {
                                if(a[r-t][j-t] != '1') ok = false;
                                if(a[r-t][j+t] != '1') ok = false;
                            }
                            if(!check( r, j, 1 + 2 + 4)) ok = false;
                            if(!check( u1, j - len + 1, 4 + 8 + 16)) ok = false;
                            if(!check( u1, j + len - 1, 1 + 128 + 64)) ok = false;
                            for(int t=1;t<len;++t) if(!check( i + t, j - t, 4 + 8 + 16 + 32 + 64)) ok = false;
                            for(int t=1;t<len;++t) if(!check( i + t, j + t, 16 + 32 + 64 + 128 + 1)) ok = false;
                            for(int t=1;t<len;++t) if(!check( r - t, j - t, 1 + 2 + 4 + 8 + 16)) ok = false;
                            for(int t=1;t<len;++t) if(!check( r - t, j + t, 1 + 2 + 4 + 64 + 128)) ok = false;
                            nd = 0;
                            for(int t=0;t<len;++t) ds[nd++] = make_pair( i + t, j - t), ds[nd++] = make_pair( i + t, j + t), ds[nd++] = make_pair( r - t, j-t),
                                ds[nd++] = make_pair( r - t, j + t);
                            
                            if(ok && check2()) ++res;
                        }
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}