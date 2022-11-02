#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
const int MxN = 1e5 + 1;
int n, a[MxN], pa=-1, pb=-1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]!=pa && a[i]!=pb) {
            ans++;
            if (i<n-1 && a[i+1]==pa) pa=a[i];
            else pb = a[i];
        } else if (a[i]!=pa) {
            ans++;
            pa = a[i];
        } else if (a[i] != pb) {
            ans++;
            pb = a[i];
        }
    }
    cout << ans << endl;
}