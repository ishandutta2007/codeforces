#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100;

int n, s;
vector <int> seg[Maxn];

int main()
{
    int i, j, k, v, t, bef1, bef2, now1, now2, p1, p2, left1, left2, tosub, ans = 0;
    cin >> n >> s;
    for (i = 0; i < n; i++) {
        cin >> k;
        for (j = 0; j < k; j++) {
            cin >> v >> t;
            seg[i].push_back(t);
            seg[i].push_back(v);
        }
    }
    for (i = 0; i < n; i++)
       for (j = i+1; j < n; j++) {
           left1 = left2 = bef1 = bef2 = p1 = p2 = now1 = now2 = 0;
           while (p1 < seg[i].size() && p2 < seg[j].size()) {
                 if (!left1) left1 = seg[i][p1];
                 if (!left2) left2 = seg[j][p2];
                 tosub = min(left1, left2);
                 left1 -= tosub; left2 -= tosub;
                 now1 += tosub * seg[i][p1+1];
                 now2 += tosub * seg[j][p2+1];
                 if (bef1 < bef2 && now1 > now2 || bef1 > bef2 && now1 < now2) ans++;
                 if (now1 != now2) {
                          bef1 = now1; bef2 = now2;
                 }
                 if (!left1) p1 += 2;
                 if (!left2) p2 += 2;
           }
       }
    cout << ans << endl;
    return 0;
}