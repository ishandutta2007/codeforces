#include <bits/stdc++.h>

using namespace std;

int hy, ay, dy, hm, am, dm, hc, ac, dc;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    cin >> hy >> ay >> dy >> hm >> am >> dm >> hc >> ac >> dc;

    int ans = 100000000;
    for (int j=0; j<=300; j++)
        for (int k=0; k<=300; k++) {
            int a = ay+j, d = dy+k;
            int sy = max(0, a-dm);
            int sm = max(0, am-d);
            if (sy == 0) continue;
            int n = (hm-1)/sy+1;
            int i = max(0, n*sm+1-hy);
            ans = min(ans, hc*i+ac*j+dc*k);
        }
    cout << ans;
}