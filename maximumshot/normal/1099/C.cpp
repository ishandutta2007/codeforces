#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    string s;

    cin >> s;

    int k;

    cin >> k;

    int n = (int)s.size();
    int st = count(s.begin(), s.end(), '*');
    int qs = count(s.begin(), s.end(), '?');

    if(st > 0) {
        if(n - 2 * (st + qs) > k) {
            cout << "Impossible\n";
            return 0;
        }
        int hv = n - 2 * (st + qs);
        for(int i = 0;i < n;i++) {
            if(i + 1 < n && s[i + 1] == '?') continue;
            if(s[i] == '?') continue;
            if(s[i] == '*') continue;
            if(i + 1 < n && s[i + 1] == '*') {
                while(hv < k) {
                    cout << s[i];
                    hv++;
                }
            }else
                cout << s[i];
        }
        cout << "\n";
    }else {
        if(n - 2 * qs > k || n - qs < k) {
            cout << "Impossible\n";
            return 0;
        }
        int hv = n - 2 * qs;
        for(int i = 0;i < n;i++) {
            if(s[i] == '?') continue;
            if(i + 1 < n && s[i + 1] == '?') {
                if(hv < k) {
                    cout << s[i];
                    hv++;
                }
            }else {
                cout << s[i];
            }
        }
        cout << "\n";
    }

    return 0;
}