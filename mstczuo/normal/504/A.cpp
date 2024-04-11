# include <iostream>
# include <cstdio>
# include <cstring>
# include <stack>
# include <vector>
# include <algorithm>

using namespace std;
const int MAXN = 1<<17;
int deg[MAXN], a[MAXN];
stack<int> s;
vector<pair<int,int> > ans;

int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &deg[i], &a[i]);
        if(deg[i] == 1) s.push(i);
    }
    while(!s.empty()) {
        int x = s.top(); s.pop();
        if(deg[x] != 1) continue;
        int y = a[x];
        int tx = x, ty = y;
        if(tx > ty) swap(tx, ty);
        ans.push_back( make_pair(tx, ty));
        a[y] ^= x;
        deg[x] -= 1;
        deg[y] -= 1;
        if(deg[y] == 1) s.push(y);
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    printf("%d\n", (int)ans.size());
    for(size_t k=0;k<ans.size();++k)
        printf("%d %d\n",ans[k].first,ans[k].second);
    return 0;
}