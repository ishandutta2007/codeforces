#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int Sum(int a, int b) {
    return (a + b) % mod;
}

inline void Add(int & x, int y) {
    x = Sum(x, y);
}

inline int Raz(int a, int b) {
    return ((a - b) % mod + mod) % mod;
}

inline int Mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int Mul(vec< int > arr) {
    int res = 1;
    for(int x : arr) res = Mul(res, x);
    return res;
}

int binpow(int x, int p) {
    if(!p) return 1;
    int q = binpow(x, p / 2);
    q = Mul(q, q);
    if(p % 2) q = Mul(x, q);
    return q;
}

int const N = 305;

int n;
int a[N];
int C[N][N];
int fact[N];

void precalc() {
    for(int i = 0;i < N;i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1;j < i;j++) {
            C[i][j] = Sum(C[i - 1][j - 1], C[i - 1][j]);
        }
    }
    fact[0] = 1;
    for(int i = 1;i < N;i++) {
        fact[i] = Mul(fact[i - 1], i);
    }
}

int dp[N][N];

int main() {

    precalc();

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        for(int j = 2;j * j <= a[i];j++) {
            while(a[i] % (j * j) == 0) {
                a[i] /= j * j;
            }
        }
    }

    sort(a + 1, a + n + 1);

    vec< int > arr;

    for(int i = 1;i <= n;i++) {
        int j = i;
        while(j <= n && a[i] == a[j]) j++; j--;
        arr.push_back(j - i + 1);
        i = j;
    }

    sort(arr.rbegin(), arr.rend());

    int S = arr[0];

    dp[S][S - 1] = 1;

    int cf = fact[arr[0]];

    for(int i = 1;i < (int)arr.size();i++) {
        int x = arr[i];
        cf = Mul(cf, fact[x]);
        for(int prev = 0;prev < S;prev++) {
            if(dp[S][prev] == 0) continue;
            for(int add = 0;add < x;add++) {
                int cbl = x - add;
                for(int cut = 0;cut <= min(cbl, prev);cut++) {
//                    if(S + x == 3 && prev - cut + add == 1) {
//                        cout << S << " " << prev << "!\n";
//                    }
                    Add(dp[S + x][prev - cut + add], Mul({dp[S][prev], C[x - 1][add], C[prev][cut], C[S - prev + 1][cbl - cut]}));
                }
            }
        }
        S += x;
    }

//    cout << "# ";
//    for(int x : arr) cout << x << " ";
//    cout << "\n";

//    for(int i = 0;i <= 4;i++) {
//        for(int j = 0;j < i;j++) {
//            cout << dp[i][j] << " \n"[j + 1 == i];
//        }
//    }

    printf("%d\n", Mul(dp[S][0], cf));

    return 0;
}