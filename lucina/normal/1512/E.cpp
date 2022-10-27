#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 5;


int main() {


    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;
    for (int _ = 1 ; _ <= T ; ++ _) {
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        static bool vis[512];
        fill(vis + 1, vis + 1 + n, false);
        vector <int> bar;
        {
            int len = r - l + 1, sum = 0;
            for (int i = 1 ; i <= len ; ++ i) {
                bar.push_back(i);
                sum += i;
            }
            if (sum > s) {
                cout  << "-1\n";
                continue;
            }
            int need = s - sum;
            int cap = n;
            for (int i = len - 1 ; i >= 0 ; -- i) {
                int has = cap - bar[i];
                if (need <= has) {
                    bar[i] += need;
                    need = 0;
                    break;
                } else {
                    bar[i] = cap;
                    need -= has;
                    cap -= 1;
                }
            }
            if (need > 0) {
                cout << "-1\n";
                continue;
            }
            for (int x : bar) vis[x] = true;
        }

        int fnt = 0;
        for (int i = 1 ; i <= n ; ++ i) {
            if (vis[i]) continue;
            if (fnt >= l - 1) bar.push_back(i);
            else {
                cout << i << ' ';
                ++ fnt;
            }
        }
        for (int x : bar) cout << x << ' ';
        cout << '\n';

    }

}