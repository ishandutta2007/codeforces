#include <bits/stdc++.h>

using namespace std;

#define FOR(i, p, n) for (int i = (int)(p); i < (int)(n); ++i)
#define FORD(i, p, n) for (int i = (int)(p); i >= (int)(n); --i)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define RE scanf
#define WR printf
#define SKP scanf("%*c")

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

int main() {

    int n;

    cin >> n;

    set< pair< long long, long long  > > seg;
    seg.insert({0ll, 0ll});

    for(int s, d, i = 0;i < n;i++) {
        cin >> s >> d;
        int ok = 1;
        for(auto cur : seg) {
            if(max(LL(s), cur.first) <= min(LL(s + d - 1), cur.second)) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            cout << s << " " << s + d - 1 << "\n";
            seg.insert({s, s + d - 1});
        }else {
            int ql, qr;
            for(auto it = seg.begin();it != seg.end();it++) {
                auto nxt = it;
                nxt++;
                if(nxt == seg.end() || it->second + d < nxt->first) {
                    ql = it->second + 1;
                    qr = ql + d - 1;
                    break;
                }
            }
            cout << ql << " " << qr << "\n";
            seg.insert({ql, qr});
        }
    }

    return 0;
}