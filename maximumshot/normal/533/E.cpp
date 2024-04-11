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
#include <stack>
#include <queue>
#include <list>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll base = inf + 7;

const ll p = 109ll;
const int NMAX = 100100;

ll w1[NMAX];
ll w2[NMAX];

const ll mod1 = inf + 7;
const ll mod2 = inf + 9;

struct Hash {
    int len;
    ll value1;
    ll value2;

    Hash() {
        len = value1 = value2 = 0;
    }
    
    Hash operator + (const Hash & b)  {
        Hash ans;
        ans.len = b.len + len;
        ans.value1 = (b.value1 + w1[b.len] * value1 % mod1) % mod1;
        ans.value2 = (b.value2 + w2[b.len] * value2 % mod2) % mod2;
        return ans;
    }

    Hash operator - (const Hash & b) {
        Hash ans;
        ans.len = len - b.len;
        ans.value1 = value1 - w1[len - b.len] * b.value1;
        ans.value2 = value2 - w2[len - b.len] * b.value2;
        ans.value1 = (ans.value1 % mod1 + mod1) % mod1;
        ans.value2 = (ans.value2 % mod2 + mod2) % mod2;
        return ans;
    }

    bool operator < (const Hash & b) const {
        if(len < b.len) return 1;
        else if(len > b.len) return 0;
        else return mp(value1, value2) < mp(b.value1, b.value2);
    }

    bool operator == (const Hash & b) const {
        return mt(value1, value2, len) == mt(b.value1, b.value2, b.len);
    }

    bool operator > (const Hash & b) const {
        return !(*this < b && *this == b);
    }
};

Hash make_hash(ll v, int ll = 1) {
    Hash ans;
    ans.len = ll;
    ans.value1 = ans.value2 = v;
    ans.value1 = (ans.value1 % mod1 + mod1) % mod1;
    ans.value2 = (ans.value2 % mod2 + mod2) % mod2;
    return ans;
}

void read(string & s) {
    char buffer[NMAX];
    scanf("%s", &buffer);
    s = buffer;
}

void init() {
    w1[0] = w2[0] = 1ll;
    for(int i = 1;i < NMAX;i++) {
        w1[i] = (w1[i - 1] * p) % mod1;
        w2[i] = (w2[i - 1] * p) % mod2;
    }
}

bool solve() 
{
    init();
    int n;
    scanf("%d", &n);

    string a, b;
    read(a);
    read(b);

    vec< Hash > ma, mb; 
    vec< Hash > ha(n), hb(n);

    for(int i = 0;i < n;i++) {
        if(i > 0) {
            ha[i] = ha[i - 1];
            hb[i] = hb[i - 1];
        }

        ha[i] = ha[i] + make_hash(a[i]);
        hb[i] = hb[i] + make_hash(b[i]);
    }

    for(int i = 0;i <= n;i++) {
        for(char c = 'a';c <= 'z';c++) {
            Hash t = make_hash(0, 0);
            
            if(i > 0) t = ha[i - 1];
            t = t + make_hash(c);
            if(i < n) {
                if(i > 0) t = t + (ha[n - 1] - ha[i - 1]);
                else t = t + ha[n - 1];
            }

            ma.push_back(t);

            t = make_hash(0, 0);

            if(i > 0) t = hb[i - 1];
            t = t + make_hash(c);
            if(i < n) {
                if(i > 0) t = t + (hb[n - 1] - hb[i - 1]);
                else t = t + hb[n - 1];
            }

            mb.push_back(t);
        }
    }

    sort(ALL(ma));
    sort(ALL(mb));

    ma.resize(unique(ALL(ma)) - ma.begin());
    mb.resize(unique(ALL(mb)) - mb.begin());

    int ia = 0, ib = 0, ans = 0;
    int sa = (int)ma.size();
    int sb = (int)mb.size();

    while(ia < sa && ib < sb) {
        if(ma[ia] < mb[ib]) ia++;
        else if(mb[ib] < ma[ia]) ib++;
        else ans++, ia++, ib++;
    }

    cout << ans << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();    

    return 0;
}