#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 305;

int T;
int n, k;
char B[Maxn][Maxn];
vector <int> vals;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        fill((char*)B, (char*)B + Maxn * Maxn, '0');
        vals.clear();
        int lft = k;
        for (int i = 0; i < n; i++) {
            int me = lft / (n - i); lft -= me;
            vals.push_back(me);
        }
        cout << 2ll * ll(*vals.rbegin() - *vals.begin()) * (*vals.rbegin() - *vals.begin()) << endl;
        for (int j = 0; j < n; j++)
            for (int i = 0; i < n && k > 0; i++) {
                int oth = (i + j) % n;
                B[i][oth] = '1';
                k--;
            }
        for (int i = 0; i < n; i++) {
            B[i][n] = '\0';
            printf("%s\n", B[i]);
        }
    }
    return 0;
}