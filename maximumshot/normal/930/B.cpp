#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;
const double pi = acos(-1.0);

const int N = 5005;

char s[N];
int n;
int d[26][26][N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    cout.precision(20);
    cout << fixed;

    scanf("%s", s);

    n = strlen(s);

    vec< int > freq(26);

    for(int i = 0;i < n;i++) {
        freq[s[i] - 'a']++;
        for(int j = 0;j < n;j++) {
            int dist = i <= j ? j - i : n - i + j;
            d[s[i] - 'a'][s[j] - 'a'][dist]++;
        }
    }

    vec< vec< int > > bs(26, vec< int >(n));
    vec< int > tot(26);

    for(int k = 0;k < n;k++) {
        int x = s[k] - 'a';
        int ok = 0;
        for(int q = 1;q < n;q++) {
            int j = (k + q) % n;
            int y = s[j] - 'a';
            if(d[x][y][q] == 1) {
                bs[x][q]++;
            }
        }
    }

    ld res = 0.0;

    for(int i = 0;i < 26;i++) {
        if(!freq[i]) continue;
        int ok = 0;
        int mx = 0;
        for(int q = 1;q < n;q++) {
            mx = max(mx, bs[i][q]);
            if(bs[i][q] == freq[i]) {
                ok = 1;
                break;
            }
        }
        res += 1.0 * mx;
//        if(ok) {
//            res += freq[i];
//        }
//        cout << char(i + 'a') <<  " " << 1.0 * freq[i] << " : \n";
//        for(int p = 0;p < n;p++) {
//            if(s[p] != char(i + 'a')) {
//                continue;
//            }
//            cout << p << " : ";
//            for(int q = 1;q < n;q++) {
//                int j = (p + q) % n;
//                int y = s[j] - 'a';
//                if(d[i][y][q] == 1) {
//                    cout << q << " ";
//                }
//            }
//            cout << "\n";
//        }
    }

    cout << res / n << "\n";

    return 0;
}