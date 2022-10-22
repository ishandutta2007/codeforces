#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int LOG = 63;
const int N = 5e5 + 5;

int _cnt[2 * N + 1];
int* cnt;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    cnt = _cnt + N;

    ll n;
    int k;

    cin >> n >> k;

    int tot = 0;

    for(int i = 0;i < LOG;i++) {
        if((1ll << i) & n) {
            cnt[i]++;
            tot++;
        }
    }

    if(tot > k) {
        puts("No");
        return 0;
    }

    puts("Yes");

    for(int i = N;i > -N;i--) {
        if(tot + cnt[i] <= k) {
            tot += cnt[i];
            cnt[i - 1] += cnt[i] * 2;
            cnt[i] = 0;
        }else {
            break;
        }
    }

    vec< int > res;

    for(int i = N;i >= -N;i--) {
        for(int j = 0;j < cnt[i];j++) {
            res.push_back(i);
        }
    }

    while((int)res.size() < k) {
        int x = res.back();
        res.pop_back();
        res.push_back(x - 1);
        res.push_back(x - 1);
    }

    for(int x : res) {
        printf("%d ", x);
    }

    printf("\n");

    return 0;
}