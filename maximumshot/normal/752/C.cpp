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
    scanf("%d", &n);

    char c;

    vec< char > used(26, 0);

    int res = 1;

    string can[] = {
        "LU", "LD",
        "RU", "RD",
        "R", "L", "U", "D"
    };

    int sz = sizeof(can) / sizeof(string);

    for(int i = 0;i < sz;i++) {
        sort(ALL(can[i]));
    }

    string cur = "";

    for(int i = 0;i < n;i++) {
        scanf(" %c", &c);
        cur.push_back(c);
        sort(ALL(cur));
        cur.resize( unique(ALL(cur)) - cur.begin() );
        int ok = 0;
        for(int j = 0;j < sz;j++) {
            if(can[j] == cur) {
                ok = 1;
                break;
            }
        }
        if(!ok) {
//            cout << cur << "\n";
            res++;
            cur = "";
            cur.push_back(c);
        }
    }

    printf("%d\n", res);

    return 0;
}