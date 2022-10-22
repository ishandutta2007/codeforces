#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

const int A[] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

pair<bool, int> conv(int x) {
    int h = x / 10, l = x % 10;
    if (A[h] == -1 || A[l] == -1) return {false, 0};
    int ret = A[l] * 10 + A[h];
    return {true, ret};
}

int main() {
    int tt;
    scanf("%d", &tt);
    while(tt--) {
        int h, m;
        scanf("%d%d", &h, &m);
        char s[10];
        int hh, mm;
        scanf("%d:%d", &hh, &mm);
        //int hh = (s[0] - '0') * 10 + (s[1] - '0');
        //int mm = (s[3] - '0') * 10 + (s[4] - '0');
        auto is_valid = [&](int hh, int mm) {
            auto [ok1, hh2] = conv(mm);
            auto [ok2, mm2] = conv(hh);
            return ok1 && ok2 && hh2 < h && mm2 < m;
        };
        while(!is_valid(hh, mm)) {
            mm++;
            if (mm == m) {
                mm = 0;
                hh++;
                if (hh == h) hh = 0;
            }
        }
        printf("%02d:%02d\n", hh, mm);
    }
}