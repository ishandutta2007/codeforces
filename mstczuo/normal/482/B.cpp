# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
# include <vector>

using namespace std;
typedef pair<int,int> pii;

int n;
bool v[100010];
int s[100010];
bool solve(vector<pii>&a,vector<pii>&b) {
    for(int i = 1; i <= n; ++i) v[i] = 0;
    int sz = a.size(), p = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < sz; ++i) {
        if(p < a[i].first) p = a[i].first;
        while(p <= a[i].second) v[p++] = true;
    }
    s[0] = 0;
    for(int i = 1; i <= n; ++i) 
        s[i] = s[i-1] + v[i];
    for(size_t i = 0; i < b.size(); ++i) 
        if(s[b[i].second] - s[b[i].first-1] == b[i].second - b[i].first + 1)
            return false;
    return true;
}

int ans[100010];
vector<pii> c[32], d[32];
int main() {
    int m, l, r, x;
    cin >> n >> m;
    while(m--) {
        cin >> l >> r >> x;
        for(int k = 0; k < 30; ++k, x>>=1) 
            if(x & 1) c[k].push_back(pii(l,r));
            else d[k].push_back(pii(l,r));
    }
    bool flag = true;
    for(int k = 0; k < 30; ++k) {
        if(!solve(c[k], d[k])) {
            flag = false; break;
        }
        for(int i = 1; i <= n; ++i) {
            if(v[i]) ans[i] |= (1<<k);
        }
    }
    if(!flag) puts("NO");
    else {
        puts("YES");
        for(int i = 1; i <= n; ++i)
            printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}