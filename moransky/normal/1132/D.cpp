#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200005, K = N;
struct Node{
    LL a, b, cost;
    bool operator < (const Node &x) const {
        if(cost != x.cost) return cost > x.cost;
        if(b != x.b) return b > x.b;
        return a > x.a;
    }
};
int n, k, b[N];
LL a[N];
priority_queue<Node> q;
//x
bool check(LL x) {
    while(!q.empty()) q.pop();
    for(int i = 1; i <= n; i++) 
        if(a[i] / b[i] < k) q.push((Node){ a[i], b[i], a[i] / b[i]});
    for(int i = 0; i < k; i++) {
        if(q.empty()) break;
        Node u = q.top(); q.pop();
        if(u.cost < i) return false;
        if((u.a + x) / u.b < k) 
            q.push((Node){u.a + x, u.b, (u.a + x) / u.b});  
    }
    return true;
}
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for(int i = 1; i <= n; i++)
        scanf("%d", b + i);
    LL l = 0, r = 2e12;
    while(l < r) {
        LL mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(check(r)) printf("%lld\n", r);
    else puts("-1");
    return 0;
}