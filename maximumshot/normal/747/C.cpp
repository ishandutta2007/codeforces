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

    int n, q;

    scanf("%d %d", &n, &q);

    vec< int > t(q), k(q), d(q);
    vec< vec< int > > a(2e6);
    vec< set< int > > b(q);

    set< int > free;

    for(int i = 1;i <= n;i++) free.insert(i);

    for(int cur_time = 0, iter = 0;iter < q;iter++) {
        scanf("%d %d %d", &t[iter], &k[iter], &d[iter]);

        while(cur_time <= t[iter]) {
            for(int idx : a[cur_time]) {
                for(int x : b[idx]) {
                    free.insert(x);
                }
            }
            cur_time++;
        }

        if((int)free.size() < k[iter]) {
            puts("-1");
            continue;
        }
        set< int > now;
        int sum = 0;
        for(int it = 0;it < k[iter];it++) {
            sum += *free.begin();
            now.insert(*free.begin());
            free.erase(free.begin());
        }
        printf("%d\n", sum);
        b[iter] = now;
        a[ t[iter] + d[iter] ].push_back(iter);
    }


    return 0;
}