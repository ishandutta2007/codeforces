#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef long long ll;
typedef pair< int, int > pii;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const K = 14;
int const N = 1e5 + 5;
int const X = 1e4 + 5;

int n, k;
int a[N];

void read() {
    scanf("%d %d", &n, &k);
    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
}

vec< int > cur[K + 1];

void init() {
    for(int mask = 0;mask < (1 << K);mask++) {
        cur[ __builtin_popcount(mask) ].push_back(mask);
    }
}

ll simple_solve() {
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j < i;j++) {
            if(__builtin_popcount(a[i] ^ a[j]) == k) {
                res++;
            }
        }
    }
    return res;
}

int cnt[X];

ll fast_solve() {
    for(int i = 0;i < X;i++) cnt[i] = 0;
    for(int i = 1;i <= n;i++) {
        cnt[a[i]]++;
    }
    ll res = 0;
    for(int i = 0;i < X;i++) {
        if(!cnt[i]) continue;
        if(k == 0) {
            res += 1ll * cnt[i] * (cnt[i] - 1) / 2;
            continue;
        }
        for(int mask : cur[k]) {
            if((i ^ mask) < i) {
                res += 1ll * cnt[i] * cnt[i ^ mask];
            }
        }
    }
    return res;
}

void stress() {
    srand(time(NULL));
    init();
    int const maxn = 5e3;
    int const maxx = 1e4;
    while(1) {
//        while(1) {
//            n = rand() % maxn + 1;
//            if(n >= 2) break;
//        }
        n = 1e5;
        for(int i = 1;i <= n;i++) {
            a[i] = rand() % (maxx + 1);
        }
        for(k = 0;k <= 14;k++) {
//            ll ss = simple_solve();
            double t1 = clock();
            ll fs = fast_solve();
            double t2 = clock();
            cout << "n = " << n << "; res = " << fs << "\n";
            cout << setprecision(5) << fixed << (t2 - t1) / CLOCKS_PER_SEC << " sec/\n";
            //            if(ss != fs) {
//                cout << "WA!\n";
//                cout << "Exptected : " << ss << "\n";
//                cout << "Found : " << fs << "\n\n";
//                cout << n << " " << k << "\n";
//                for(int i = 1;i <= n;i++) {
//                    cout << a[i] << " ";
//                }
//                cout << "\n";
//                int xxx;
//                cin >> xxx;
//            }else {
//                cout << "OK n = " << n << " & " << ss << " = " << fs << "\n";
//            }
        }
    }
}

int main() {

    init();
    read();
    printf("%I64d\n", fast_solve());
//    stress();

    return 0;
}