#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    vector < int > all;
    cin >> n >> m;
    all.resize(n);
    vector < int > dif;
    for (int i = 0; i < n; i++) {
        cin >> all[i];
    }
    for (int i = 0; i + 1 < n; i++) {
        dif.push_back(all[i + 1] - all[i]);
    }
    int nn = n - 1;
    int l, r;
    l = 0;
    r = -1;
    vector<int> d1 (nn);
    for(int i = 0; i < nn; i++){
        int k = 0;
        if(i > r) k = 1;
        else k = min(d1[l + r - i], r - i);
        while(0 <= i-k && i+k < n && dif[i - k] == dif[i + k]) k++;
            d1[i] = k;
        if(i + k - 1 > r) {
            r = i + k - 1, l = i - k + 1;
        }
    }
    vector<int> d2 (nn);
    l=0, r=-1;
    for(int i = 0; i < nn; i++){
        int k = 0;
        if(i > r) k = 0;
        else k = min(d2[l + r - i + 1], r - i + 1);
        while(i + k < nn && i - k - 1 >= 0 && dif[i+k] == dif[i - k - 1]) k++;
        d2[i] = k;
        if(i + k - 1 > r) {
            l = i - k, r = i + k - 1;
        }
    }
    vector < int > ans;
    for (int i = 0; i < n; i++) {
        int s1 = all[i] + all[n - 1];
        ///cout << i << endl;
        if (i > 0) {
            int s2 = all[0] + all[i - 1];
            //if (i == 2) cout << s1 << " " << s2 << endl;
            if (s1 - s2 != m) continue;
        }
        bool ok1 = true;
        bool ok2 = true;
        
        if (i >= 2) {
            if ((i - 2) % 2 == 1) {
                int mid = (i - 1) / 2;
                if (d2[mid] != mid) {
                    ok1 = false;
                    continue;
                }
            }
            else {
                int mid = (i - 2) / 2;
                if (d1[mid] != mid + 1) {
                    ok1 = false;
                    continue;
                }
            }
        }
        if (i <= n - 2) {
            int len = n - 2 - i + 1;
            if (len % 2 == 0) {
                int mid = (n - 2 + i + 1) / 2;
                if (d2[mid] != n - 1 - mid) {
                    ok2 = false;
                    continue;
                }
            }
            else {
                int mid = (n - 2 + i) / 2;
                if (d1[mid] != n - 1 - mid) {
                    ok2 = false;
                    continue;
                }
            }
        }
        if (ok1 && ok2) ans.push_back(s1 % m);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int v : ans) cout << v << " ";
    return 0;
}