#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
bool LOCAL = false;
int a1, a2, b1, b2;
int ask(int x1, int y1, int x2, int y2) {
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    if (LOCAL) {
        int cnt = 0;
        if (a1 >= x1 && a1 <= x2 && b1 >= y1 && b1 <= y2) cnt++;
        if (a2 >= x1 && a2 <= x2 && b2 >= y1 && b2 <= y2) cnt++;
        return cnt % 2;
    }
    else {
        int ans;
        cin >> ans;
        return ans % 2;
    }
}
int n;
const int maxN = 1005;
int rows[maxN], cols[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    if (LOCAL) {
        cin >> a1 >> b1 >> a2 >> b2;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cols[i] = ask(1, 1, n, i);
    }
    for (int i = 1; i <= n; i++) {
        rows[i] = ask(1, 1, i, n);
    }
    int stR = -1, enR = -1;
    int stC = -1, enC = -1;
    for (int i = 1; i <= n; i++) {
        if (rows[i] == 1) {
            if (stR == -1) stR = i;
            enR = i;
        }
        if (cols[i] == 1) {
            if (stC == -1) stC = i;
            enC = i;
        }
    }
    assert(max(stR, stC) > -1);
    if (stR != -1 && stC != -1) {
        enR++;
        enC++;
        int f = ask(1, 1, stR, stC);
        if (f == 1) {
            cout << "! " << stR << " " << stC << " " << enR << " " << enC << endl;
            return 0;
        }
        else {
            cout << "! " << stR << " " << enC << " " << enR << " " << stC << endl;
            return 0;
        }
    }
    else {
        if (stR != -1) {
            enR++;
            int l = 0;
            int r = n;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if ((mid != 0) && ask(1, 1, stR, mid)) r = mid;
                else l = mid;
            }
            cout << "! " << stR << " " << r << " " << enR << " " << r << endl;
        }
        else {
            enC++;
            int l = 0;
            int r = n;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if ((mid != 0) && ask(1, 1, mid, stC)) r = mid;
                else l = mid;
            }
            cout << "! " << r << " " << stC << " " << r << " " << enC << endl;
        }
    }
    return 0;
}