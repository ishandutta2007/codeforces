#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1505;

int n;
char s[N];
int vl[N][26];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %s", &n, s);

    for(int m_i = 1;m_i <= n;m_i++) {
        for(char c = 'a';c <= 'z';c++) {
            int cur = 0;
            for(int l = 0, r = 0;r < n;r++) {
                if(s[r] != c) cur++;
                while(cur > m_i) {
                    if(s[l] != c) {
                        cur--;
                    }
                    l++;
                }
                vl[m_i][c - 'a'] = max(vl[m_i][c - 'a'], r - l + 1);
            }
        }
    }

    int q;

    scanf("%d", &q);

    int m_i;
    char c;

    for(int iter = 0;iter < q;iter++) {
        scanf("%d %c", &m_i, &c);
        printf("%d\n", vl[m_i][c - 'a']);
    }

    return 0;
}