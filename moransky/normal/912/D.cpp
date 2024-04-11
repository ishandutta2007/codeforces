#include <cstdio>
#include <iostream>
#include <set>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int N = 100005;
int n, m, r, k;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
LL tot = 0;
set<PII> st;

LL cal(int x, int y) {
    return (LL)(min(n, x + r - 1) - max(x, r) + 1) * (min(m, y + r - 1) - max(r, y) + 1);
}

struct Node{
    int x, y;
    LL cost;
    Node(){}
    Node(int x, int y): x(x), y(y), cost(cal(x, y)) {}
    bool operator < (const Node &x) const{
        return cost < x.cost;
    }
};
priority_queue<Node> q;
int main(){
    scanf("%d%d%d%d", &n, &m, &r, &k);
    q.push(Node((n + 1) >> 1, (m + 1) >> 1));
    st.insert(make_pair((n + 1) >> 1, (m + 1) >> 1));
    for(int i = 1; i <= k; i++) {
        Node u = q.top(); q.pop();
        tot += u.cost;
        for(int i = 0; i < 4; i++) {
            int nx = u.x + dx[i], ny = u.y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m || st.count(make_pair(nx, ny))) continue;
            st.insert(make_pair(nx, ny));
            q.push(Node(nx, ny));
        }
    }
    double sum = (LL)(n - r + 1) * (m - r + 1);
    printf("%.9lf\n", tot / sum);
    return 0;
}