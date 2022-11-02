# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <map>

using namespace std;

struct seg {
    int l, r, val;
};

vector<seg> v[100010];
int a[100010];

int gcd(int a,int b) {
    for(int t; b; t=a,a=b,b=t%a);
    return a;
}
map<int,long long> e;

int main() {
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    v[n].push_back((seg){n, n, a[n]});
    for(int i = n - 1; i; --i) {
        int sz = v[i + 1].size();
        v[i].push_back((seg){i,i,a[i]});
        for(int j = 0; j < sz; ++j) {
            int t = gcd(a[i], v[i+1][j].val);
            if(t == v[i].rbegin()->val) {
                v[i].rbegin()->r = v[i+1][j].r;
            } else {
                v[i].push_back(v[i+1][j]);
                v[i].rbegin()->val = t;
            }
        }
    }

    for(int i = 1; i <= n; ++i)
        for(size_t j = 0; j < v[i].size(); ++j)
            e[v[i][j].val] += v[i][j].r - v[i][j].l + 1;

    int m; scanf("%d", &m);
    int x;
    for(int i = 0; i < m; ++i) {
        scanf("%d", &x);
        if(e.find(x) == e.end()) puts("0");
        else printf("%I64d\n", e[x]);
    }
    return 0;
}