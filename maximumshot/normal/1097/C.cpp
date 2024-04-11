#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 5e5 + 5;
char buffer[N];

inline void read_string(string &s) {
    scanf("%s", buffer);
    s = buffer;
}

bool check(const string &s) {
    int b = 0;
    for(char c : s) {
        if(c == '(') {
            b++;
        }else {
            b--;
        }
        if(b < 0) return 0;
    }
    return b == 0;
}

int check_l(const string &s) {
    int b = 0;
    for(char c : s) {
        if(c == '(') {
            b++;
        }else {
            b--;
        }
        if(b < 0) return -1;
    }
    return b;
}

int check_r(const string &s) {
    int b = 0;
    for(int i = (int)s.size() - 1;i >= 0;i--) {
        char c = s[i];
        if(c == '(') {
            b--;
        }else {
            b++;
        }
        if(b < 0) return -1;
    }
    return b;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    int ok = 0;

    vector< int > cl(N), cr(N);

    for(int i = 0;i < n;i++) {
        string t;
        read_string(t);
        int x;
        if(check(t)) {
            ok++;
        }else if((x = check_l(t)) != -1) {
            cl[x]++;
        }else if((x = check_r(t)) != -1) {
            cr[x]++;
        }
    }

    int res = ok / 2;

    for(int i = 0;i < N;i++) {
        res += min(cl[i], cr[i]);
    }

    printf("%d\n", res);

    return 0;
}