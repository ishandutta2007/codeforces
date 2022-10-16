#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M;
bool a[502][502];
char c[502];
int d[502];

int main(void) {
    cin >> N >> M;
    int u, v;
    ff(i, 1, N) ff(j, i + 1, N) a[i][j] = a[j][i] = 1;
    ff(i, 1, N) d[i] = N - 1;
    ff(i, 1, M) {
        cin >> u >> v;
        a[u][v] = a[v][u] = 0; --d[u]; --d[v];
    }
    ff(i, 1, N) if (d[i] == 0) c[i] = 'b';
    ff(i, 1, N) if (d[i] != 0) {
        c[i] = 'a';
        ff(j, 1, N) if (a[i][j]) c[j] = 'c';
        break;
    }
    ff(i, 1, N) if (c[i] != 'b' && c[i] != 'c') c[i] = 'a';
    ff(i, 1, N) ff(j, 1, N) if (i != j) {
        if (c[i] == 'a' && c[j] == 'c' && a[i][j] == 0) { cout << "No" << endl; return 0; }
        if (c[i] == c[j] && a[i][j] == 1) { cout << "No" << endl; return 0; }
    }
    cout << "Yes" << endl;
    ff(i, 1, N) cout << c[i]; cout << endl;
    return 0;
}