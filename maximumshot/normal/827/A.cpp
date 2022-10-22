#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int L = 2e6 + 5;

char buffer[L];

inline void read_string(string& s) {
    scanf("%s", buffer);
    s = buffer;
}

int n, m;
string s[L];
vec< int > p[L];
char res[L];
int nxt[L];
int used[L];

int _next(int i) {
    if(i == m) return i;
    if(used[nxt[i]]) {
        nxt[i] = _next(nxt[i]);
    }
    return nxt[i];
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 0;i < n;i++) {
        read_string(s[i]);
        int k;
        scanf("%d", &k);
        p[i].resize(k);
        for(int j = 0;j < k;j++) {
            scanf("%d", &p[i][j]);
            p[i][j]--;
            m = max(m, p[i][j] + (int)s[i].size());
        }
    }

    for(int i = 0;i < m;i++) {
        res[i] = 'a';
        nxt[i] = i + 1;
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < (int)p[i].size();j++) {
            int x = p[i][j];
            while(x < p[i][j] + (int)s[i].size()) {
                if(used[x]) x = _next(x);
                if(x >= p[i][j] + (int)s[i].size()) break;
                used[x] = 1;
                res[x] = s[i][x - p[i][j]];
//                cout << x << "\n";
            }
        }
    }

//    for(int i = 0;i < m;i++) {
//        cout << res[i] << " ";
//    }

//    cout << "\n";

    printf("%s\n", res);

    return 0;
}