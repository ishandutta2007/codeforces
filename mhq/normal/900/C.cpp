#include <bits/stdc++.h>
using namespace std;
int n;
vector < int > pr;
const int maxN = (int)1e5 + 7;
vector < int > fi;
vector < int > se;
bool used1[maxN];
bool used2[maxN];
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int mx1 = -1;
    int mx2 = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > mx1) {
            mx2 = mx1;
            mx1 = a[i];
            used1[i] = true;
            fi.push_back(a[i]);
        }
        else if (a[i] > mx2) {
            mx2 = a[i];
            used2[i] = true;
            se.push_back(a[i]);
        }
    }
    int del1 = 0;
    int del2 = 0;
    int mxa = -1;
    int va = -1;
    for (int i = 1; i <= n; i++) {
        int ans = fi.size();
        int val = a[i];
        if (used1[i] == true) ans--;
        if (used2[i]) del2++;
        int l = del2;
        int r = se.size() - 1;
        if (l <= r) {
            if (!used2[i]) {
                if (val > se[r]) {
                    ans += r - l + 1;
                }
                else if (val > se[l]) {
                    while (r > l + 1) {
                        int mid = (l + r) / 2;
                        if (val > se[mid]) l = mid;
                        else r = mid;
                    }
                    ans += l - del2 + 1;
                    //if (used2[i]) ans--;
                }
            }
        }
        //cout << ans << '\n';
        if (ans > mxa || (ans == mxa && val < va)) {
            va = val;
            mxa = ans;
        }
    }
    cout << va;
    return 0;
}