#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(100);
}
#define int ll
void solve(){
    string s;
    getline(cin, s);
    s.push_back(' ');
    string b;
    vector<string> go;
    int now_go = 0;
    REP(i, s.length()) {
        if (s[i] == '"') {
            now_go++;
            if (now_go % 2 == 0) {
                go.push_back(b);
                b.clear();
            }
        }
        else {
            if (now_go % 2 == 1) {
                b.push_back(s[i]);
            }
            else {
                if (s[i] == ' ') {
                    if (b.empty() == false) {
                        go.push_back(b);
                        b.clear();
                    }
                }
                else {
                    b.push_back(s[i]);
                }
            }
        }
    }
    REP(i, go.size()) {
        cout << "<" << go[i] << ">" << endl;
    }
    return;
}
#undef int
int main() {
    init();
    solve();
}