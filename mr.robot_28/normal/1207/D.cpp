#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;
const int MOD = 998244353;

int mul(int a, int b){
    return (a * 1LL * b) % MOD;
}


int sum(int a, int b){
    return (a + b) % MOD;
}

int n;
pair<int, int> a[N];
int f[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d%d", &a[i].first, &a[i].second);

    f[0] = 1;
    for(int i = 1; i < N; ++i)
        f[i] = mul(i, f[i - 1]);

    int res = f[n];
    for(int c = 0; c < 2; ++c){
        int d = 1;
        sort(a, a + n);
        int l = 0;
        while(l < n){
            int r = l + 1;
            while(r < n && a[l].first == a[r].first) ++r;
            d = mul(d, f[r - l]);
            l = r;
        }
        res = sum(res, MOD - d);
        for(int i = 0; i < n; ++i) 
            swap(a[i].first, a[i].second);
    }       

    sort(a, a + n);
    int l = 0;
    int d = 1;
    while(l < n){
        int r = l + 1;
        while(r < n && a[l].first == a[r].first) ++r;
        map<int, int> m;
        for(int i = l; i < r; ++i) ++m[a[i].second];
        for(auto p : m) d = mul(d, f[p.second]);
        l = r;
    }
    for(int i = 1; i < n; ++i) 
        if(a[i - 1].second > a[i].second) d = 0;

    res = sum(res, d);
    printf("%d\n", res);
    return 0;
}