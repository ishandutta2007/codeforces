#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 10111;

int v[max_n];
int n, k;
bool debug = false;

int get_or(int i, int j) {
    if (debug) {
        return v[i] | v[j];
    }
    cout << "or " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;
    return res;
}

int get_and(int i, int j) {
    if (debug) {
        return v[i] & v[j];
    }
    cout << "and " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;
    return res;
}

void finish(int x) {
    cout << "finish " << x << endl;
    exit(0);
}

mt19937 gen(228);


int m[max_n];

int O[3][3];
int A[3][3];

int main() {
    //freopen("input.txt", "r", stdin)
    //freopen("output.txt", "w", stdout);
    int n, x;
    cin >> n >> x;
    if (debug) {
        for (int i = 0; i < n; ++i) {
            v[i] = gen() % (1000000000);
        }
    }
    for (int i = 0; i < 3; i += 3) {
        for (int a = 0; a < 3; ++a) {
            for (int b = a + 1; b < 3; ++b) {
                O[a][b] = O[b][a] = get_or(i + a, i + b);
                A[a][b] = A[b][a] = get_and(i + a, i + b);
            }
        }
        for (int j = 0; j < 3; ++j) {
            int k = -1, p = -1;
            for (int o = 0; o < 3; ++o) {
                if (o == j || o == k || o == p) continue;
                if (k == -1) k = o;
                else p = o;
            }
            int b = (O[k][j] & O[j][p]);
            b ^= A[k][p];
            b |= (A[k][j] & A[j][p]);
            m[i + j] = b;
        }
    }
    for (int i = 3; i < n; ++i) {
        m[i] = (get_or(0, i) - get_and(0, i)) ^ m[0];
    }
    sort(m, m + n);
    cout << "finish " << m[x - 1] << endl;
    return 0;
}