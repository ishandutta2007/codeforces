#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<iomanip>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
mt19937 gene(233);
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
    const int maxn = 131072;
    static char buf[maxn],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
    int res(0);
    char c = getchar();
    while(c < '0') c = getchar();
    while(c >= '0') {
        res = res * 10 + (c - '0');
        c = getchar();
    }
    return res;
}

inline LL fastpo(LL x, LL n, LL mod) {
    LL res(1);
    while(n) {
        if(n & 1) {
            res = res * (LL)x % mod;
        }
        x = x * (LL) x % mod;
        n /= 2;
    }
    return res;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

inline string itoa(int x, int width = 0) {
    string res;
    if(x == 0) res.push_back('0');
    while(x) {
        res.push_back('0' + x % 10);
        x /= 10;
    }
    while((int)res.size() < width) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
    fwrite(buf, 1, _bl, stdout);
    _bl = 0;
}
__inline void _putchar(char c) {
    if(_bl == _B) flush();
    buf[_bl++] = c;
}
inline void print(LL x, char c) {
    static char tmp[20];
    int l = 0;
    if(!x) tmp[l++] = '0';
    else {
        while(x) {
            tmp[l++] = x % 10 + '0';
            x /= 10;
        }
    }
    for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
    _putchar(c);
}
struct P {
    D x, y;
};
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[N], vst[N], col[N], cnt[N][3], deg[N], blg[N], bak[N];
set<int> mp[N];
vector<int> e[N];
void calc() {
    scanf("%d", &n);
    for(int i  = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if(a[i] <= 1) a[i] ^= 1;
    }
    for(int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        e[x].pb(y);
        e[y].pb(x);
    }
    fill(vst + 1, vst + 1 + n, false);
    int cc = 0;
    for(int i = 1; i <= n; i++) {
        if(!vst[i]) {
            static vector<int> q;
            q.clear();
            q.pb(i);
            blg[i] = ++cc;
            col[cc] = a[i];
            vst[i] = true;
            for(int op = 0; op < (int)q.size(); op++) {
                int v = q[op];
                for(int y : e[v]) {
                    if(!vst[y] && a[y] == a[v]) {
                        blg[y] = blg[v];
                        vst[y] = true;
                        q.pb(y);
                    }
                }
            }
        }
    }
    

    int res = inf;
    for(int d = 0; d < 2; d++) {
        for(int i = 1; i <= n; i++) {
            for(int y : e[i]) {
                if(blg[y] != blg[i]) {
                    mp[blg[y]].insert(blg[i]);
                    mp[blg[i]].insert(blg[y]);
                    
                }
            }
        }
        copy(col + 1, col + 1 + cc, bak + 1);
        for(int i = 1; i <= cc; i++) {
            cnt[i][0] = cnt[i][2] = 0;
            deg[i] = 0;
            for(int j : mp[i]) {
                //printf("%d--%d\n", i, j);
                cnt[i][col[j]] += 1;
                deg[i]++;
                //printf("col[%d] = %d\n", i, col[i]);
            }
        }
        vector<int> q, w;
        
        for(int i = 1; i <= cc; i++) {
            vst[i] = false;
            if(col[i] == 1 && cnt[i][2] == 0) {
                col[i] = 0;
            }
            if(col[i] == 1 && cnt[i][0] == 0) {
                col[i] = 2;
            }
            if(col[i] != 1 && deg[i] <= 1) {
                vst[i] = true;
                //printf("col %d %d\n", i, col[i]);
                if(col[i] == 0) q.pb(i);
                else w.pb(i);
            }
        }
        int tmp = 0;
        for(int cur = 0; ; cur = 2 - cur) {
            tmp++;
            for(int op = 0; op < (int)q.size(); op++) {
                int v = q[op];
                //cout << tmp << ' ' << v << endl;
                for(int y : mp[v]) {
                    cnt[y][col[v]]--;
                    deg[y]--;
                    //printf("%d %d %d\n", v, y, deg[y]);
                    mp[y].erase(v);
                    if(col[y] == 1 && cnt[y][2] == 0) {
                        col[y] = 0;
                    }
                    if(col[y] == 1 && cnt[y][0] == 0) {
                        col[y] = 2;
                    }
                    if(col[y] != 1 && deg[y] <= 1 && !vst[y]) {
                        vst[y] = true;
                        if(col[y] == cur) {
                            q.pb(y);
                        }else w.pb(y);
                    }
                }
                mp[v].clear();
            }
            if(w.empty()) break;
            swap(w, q);
            w.clear();
        }
        for(int i = 1; i <= cc; i++) assert(mp[i].empty());
        res = min(res, tmp);

        copy(bak + 1, bak + 1 + cc, col + 1);

        for(int i = 1; i <= cc; i++) col[i] = 2 - col[i];
    }
    for(int i = 1; i <= n; i++) {
        e[i].clear();
    }
    printf("%d\n", res);
}
int main() {
    int t;
    scanf("%d", &t);
    for(int qq = 1; qq <= t; qq++) {
        calc();
    }
}