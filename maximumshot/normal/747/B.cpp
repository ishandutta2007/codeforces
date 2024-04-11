#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;
    string s;
    cin >> n >> s;

    if(n % 4) {
        cout << "===\n";
        return 0;
    }

    int a = 0;
    int c = 0;
    int g = 0;
    int t = 0;

    for(int i = 0;i < n;i++) {
        if(s[i] == 'A') a++;
        else if(s[i] == 'C') c++;
        else if(s[i] == 'G') g++;
        else if(s[i] == 'T') t++;
    }

    if(max({a, c, g, t}) > n / 4) {
        cout << "===\n";
        return 0;
    }

    for(int i = 0;i < n;i++) {
        if(s[i] == '?') {
            int mn = min({a, c, g, t});
            if(mn == a) {
                s[i] = 'A';
                a++;
            }else if(mn == c) {
                s[i] = 'C';
                c++;
            }else if(mn == g) {
                s[i] = 'G';
                g++;
            }else {
                s[i] = 'T';
                t++;
            }
        }
    }

    cout << s << "\n";

    return 0;
}