
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int q, n;
ll h;
ll p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> h >> n;
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }
        int cnt = 0;
        int i = 0;
        while(true) {
            if(i == n - 1) break;
            if(i == n - 2) {
                if(p[n - 1] > 1) {
                    cnt++;
                }
                break;
            }
            if(p[i + 1] == p[i + 2] + 1) {
                i += 2;
            }else {
                cnt++;
                i++;
            }
        }
        cout << cnt << endl;
    }
}