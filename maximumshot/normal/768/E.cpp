#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const S = 61;

int mex(vec< int > arr) {
    if(arr.empty()) return 0;
    sort(ALL(arr));
    arr.resize(unique(ALL(arr)) - arr.begin());
    if(arr.front() > 0) return 0;
    for(int i = 0;i + 1 < (int)arr.size();i++) {
        if(arr[i] + 1 < arr[i + 1]) {
            return arr[i] + 1;
        }
    }
    return arr.back() + 1;
}

map< pair< int, ll >, int > g;

int grundy(int x, ll mask = 0) {
    if(g.count(make_pair(x, mask))) return g[ make_pair(x, mask) ];
    if(x == 0) return g[ make_pair(x, mask) ] = 0;
    vec< int > arr;
    for(int del = 1;del <= x;del++) {
        if((1ll << del) & mask) continue;
        arr.push_back(grundy(x - del, mask | (1ll << del)));
    }
    return g[ make_pair(x, mask) ] = mex(arr);
}

int main() {

//    freopen("input.txt", "w", stdout);

    int arr[61] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10 };

    int n;

    scanf("%d", &n);

    int res = 0;

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &x);
        res ^= arr[x];
    }

    if(res) {
        puts("NO");
    }else {
        puts("YES");
    }

    return 0;
}