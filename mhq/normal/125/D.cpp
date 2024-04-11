#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = 3 * (int)1e4 + 10;
int a[maxN];
map < int, int > q;
bool used[maxN];
void solve(int ind1, int ind2, int d) {
    memset(used, 0, sizeof used);
    vector < int > ans2;
    int st = a[ind1];
    while (st != a[ind2]) {
        int p = q[st];
        if (p == 0) {
            return ;
        }
        used[p] = true;
        ans2.push_back(p);
        st += d;
    }
    used[ind2] = true;
    ans2.push_back(ind2);
    vector < int > ans;
    for (int i = 1; i < ans2.size(); i++) {
        if (ans2[i] < ans2[i - 1]) return ;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) ans.push_back(i);
    }
    int prv = -1;
    if (ans.size() == 0) return ;
    for (int i = 2; i < ans.size(); i++) {
        if (a[ans[i]] + a[ans[i - 2]] != 2 * a[ans[i - 1]]) return ;
    }
    for (int i = 2; i < ans2.size(); i++) {
        if (a[ans2[i]] + a[ans2[i - 2]] != 2 * a[ans2[i - 1]]) return ;
    }
    for (int i = 0; i < ans.size(); i++) cout << a[ans[i]] << " ";
    cout << '\n';
    for (int i = 0; i < ans2.size(); i++) cout << a[ans2[i]] << " ";
    exit(0);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q[a[i]] = i;
    }
    if (n == 1) {
        cout << "No solution";
        return 0;
    }
    if (n == 2) {
        cout << a[1] << '\n';
        cout << a[2];
        return 0;
    }
    if (n == 3) {
        cout << a[1] << " " << a[2] << '\n';
        cout << a[3];
        return 0;
    }
    if (n == 4) {
        cout << a[1] << " " << a[2] << '\n';
        cout << a[3] << " " << a[4];
        return 0;
    }
    int t = a[n] - a[1];
    int sgn;
    if (t > 0) sgn = 1;
    else sgn = -1;
    t = abs(t);
    for (int i = 1; i * i <= t; i++) {
        if (t % i == 0) {
            solve(1, n, sgn * i);
            solve(1, n, sgn * (t / i));
        }
    }
    t = a[n] - a[2];
    if (t > 0) sgn = 1;
    else sgn = -1;
    t = abs(t);
    for (int i = 1; i * i <= t; i++) {
        if (t % i == 0) {
            solve(2, n, sgn * i);
            solve(2, n, sgn * (t / i));
        }
    }
    t = a[n - 1] - a[1];
    if (t > 0) sgn = 1;
    else sgn = -1;
    t = abs(t);
    for (int i = 1; i * i <= t; i++) {
        if (t % i == 0) {
            solve(1, n - 1, sgn * i);
            solve(1, n - 1, sgn * (t / i));
        }
    }
    memset(used, 0, sizeof used);
    //int d = a[2] - a[1];
    vector < int > ans1;
    vector < int > ans2;
    int st = a[1];
    int d = a[2] - a[1];
    bool used1[maxN];
    bool used2[maxN];
    for (int i = 1; i <= n; i++){
        used1[i] = false;
        used2[i] = false;
    }
    while (1) {
        int r = q[st];
        if (r == 0) break;
        else {
            if (ans1.size() > 0) {
                if (ans1[ans1.size() - 1] > r) break;
            }
            ans1.push_back(r);
        }
        used1[r] = true;
        st += d;
    }
    st = a[n];
    d = a[n - 1] - a[n];
    while (1) {
        int r = q[st];
        if (r == 0) break;
        else {
            if (ans2.size() > 0) {
                if (ans2[ans2.size() - 1] < r) break;
            }
            ans2.push_back(r);
        }
        used2[r] = true;
        st += d;
    }
    reverse(ans2.begin(), ans2.end());
    for (int i = 1; i <= n; i++) {
        if (used1[i] == false && used2[i] == false) {
            cout << "No solution";
            return 0;
        }
    }
    vector < int > rans1;
    vector < int > rans2;
    for (int i = 1; i <= n; i++) {
        if (used1[i] && !used2[i]) rans1.push_back(i);
        if (!used1[i] && used2[i]) rans2.push_back(i);
        if (used1[i] && used2[i]) {
            if (i == ans2[0]) rans1.push_back(i);
            else if (i == ans1[ans1.size() - 1]) rans2.push_back(i);
            else {
                cout << "No solution";
            }
        }
    }
    for (int i = 0; i < rans1.size(); i++) {
        cout << a[rans1[i]] << " ";
    }
    cout << '\n';
    for (int i = 0; i < rans2.size(); i++) {
        cout << a[rans2[i]] << " ";
    }
    return 0;
}