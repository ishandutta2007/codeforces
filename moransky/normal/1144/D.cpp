#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 200010;
int n, a[N], vis[N], maxn = -1, k;
struct Operate{
    int x, i, j;
};
vector<Operate> ans;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i), vis[a[i]] ++;
        if(vis[a[i]] > maxn)
            maxn = vis[a[i]], k = a[i];
    }
    int r;
    for(int i = 1; i <= n; i++){
        if(a[i] == k){
            int l = i;
            while(--l && a[l] != k)
                ans.push_back((Operate){a[l] > k ? 2 : 1, l, l + 1});
            r = i;
        }
    }
    while(++r <= n)
        ans.push_back((Operate){a[r] > k ? 2 : 1, r, r - 1});
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d %d %d\n", ans[i].x, ans[i].i, ans[i].j);
    return 0;
}