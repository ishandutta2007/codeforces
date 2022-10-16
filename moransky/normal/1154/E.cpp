#include <cstdio>
#include <iostream>
#include <set>
#include <queue>
using namespace std;
typedef set<int>::iterator SIT;
const int N = 200010;
int n, k, a[N], ans[N], nxt[N], pre[N];
bool st[N];
priority_queue<int> q;
void remove(int i){
    pre[nxt[i]] = pre[i];
    nxt[pre[i]] = nxt[i];
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1, x; i <= n; i++){
        scanf("%d", &x);
        q.push(x);
        a[x] = i;
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }

    nxt[n] = 0;
    int now = 1;
    while(!q.empty()){
        int u = q.top(); q.pop();
        if(st[a[u]]) continue;
        st[a[u]] = true;
        ans[a[u]] = now;
        for(int loc = nxt[a[u]], i = 1; i <= k && loc; i++, loc = nxt[loc]){
            ans[loc] = now, st[loc] = true;
            remove(loc);
        }
        for(int loc = pre[a[u]], i = 1; i <= k && loc; i++, loc = pre[loc]){
            ans[loc] = now, st[loc] = true;
            remove(loc);
        }
        remove(a[u]);
        now = 3 - now;
    }
    for(int i = 1; i <= n; i++)
        printf("%d", ans[i]);
    return 0;
}