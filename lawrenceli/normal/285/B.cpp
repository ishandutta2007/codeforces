#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int n, s, t;
int p[MAXN];
bool vis[MAXN];
int num;

int main() {
    cin >> n >> s >> t;
    for (int i=1; i<=n; i++) cin >> p[i];
    while (true) {
        if (vis[s]) {
            cout << -1 << endl;
            return 0;
        }
        vis[s] = true;
        if (s==t) {
            cout << num << endl;
            return 0;
        }
        num++;
        s=p[s];
    }
}