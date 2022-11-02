#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 7000 + 10;

bool was[N][2];
int cost[N][2];
int out_deg[N][2];
vector<int> s[2];
int n;
int k1;
int k2;

int mod_add(int a, int b) {
    a -= b;
    a %= n;
    a += n;
    return a % n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    cin >> k1;
    s[0].resize(k1);
    for (int i = 0; i < k1; i++)
        cin >> s[0][i];
    cin >> k2;
    s[1].resize(k2);
    for (int i = 0; i < k2; i++)
        cin >> s[1][i];
    cost[0][0] = cost[0][1] = -1;
    for (int i = 1; i < n; i++) {
        out_deg[i][0] = k1;
        out_deg[i][1] = k2;
    }
    queue<pii> q;
    q.push(pii(0, 0));
    q.push(pii(0, 1));
    was[0][0] = was[0][1] = true;
    while (q.size()) {
        auto tp = q.front();
        q.pop();
        int x = tp.first;
        int who = tp.second;
        int ans = -1;
        if (x > 0) {
            for (int y : s[who])
                ans = max(ans, -cost[mod_add(x, -y)][1 - who]);
        }
        for (int y : s[1 - who]) {
            int to = mod_add(x, y);
            if (was[to][1 - who])
                continue;
            out_deg[to][1 - who]--;
            if (ans == -1)
                out_deg[to][1 - who] = 0;
            if (out_deg[to][1 - who] == 0) {
                was[to][1 - who] = true;
                q.push(pii(to, 1 - who));
            }
        }
        cost[x][who] = ans;
    }
    for (int who = 0; who < 2; who++) {
        for (int i = 1; i < n; i++) 
            if (cost[i][who] == 1)
                cout << "Win ";
            else if (cost[i][who] == 0)
                cout << "Loop ";
            else
                cout << "Lose ";
        cout << endl;
    }
}