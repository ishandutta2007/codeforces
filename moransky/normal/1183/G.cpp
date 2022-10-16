#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 200005;
typedef pair<int, int> PII;
int n, a[N], f[N];
PII cnt[N];
priority_queue<int> q;
//Walking on the floor
//Talking to the moon 
int main(){
    int T; scanf("%d", &T);
    cnt[0].first = 1e9;
    while(T--){
        while(!q.empty()) q.pop();
        scanf("%d", &n);
        
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", a + i, f + i);
            cnt[a[i]].first ++;
            if(f[i]) cnt[a[i]].second ++;
        }
        sort(cnt + 1, cnt + 1 + n, greater<PII>() );
        int ans1 = 0, ans2 = 0;
        int now = 1;
        for(int i = n; i; i--){
            while(cnt[now].first >= i) q.push(cnt[now++].second);
            if(q.empty()) continue;
            int u = q.top(); q.pop();
            ans1 += i, ans2 += min(u, i);
        }
        printf("%d %d\n", ans1, ans2);
        for(int i = 1; i <= n; i++) cnt[i].first = cnt[i].second = 0;
    }

    return 0;
}