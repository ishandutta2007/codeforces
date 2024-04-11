#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = (int)1e5 + 100;
int tp[maxN];
void debil1() {
    cout << "tokitsukaze";
    exit(0);
}
void debil2() {
    cout << "quailty";
    exit(0);
}
void draw() {
    cout << "once again";
    exit(0);
}
int frst[maxN];
int lst[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == '0') tp[i] = 0;
        else tp[i] = 1;
    }
    bool can_first = false;
    for (int dig = 0; dig < 2; dig++) {
        frst[0] = -1;
        int first_one = -1;
        int last_one = -1;
        for (int i = 1; i <= n; i++) {
            if (tp[i] == dig) {
                frst[i] = i;
                if (first_one == -1) first_one = i;
            }
            else frst[i] = frst[i - 1];
        }
        lst[n + 1] = -1;
        for (int i = n; i >= 1; i--) {
            if (tp[i] == dig) {
                if (last_one == -1) last_one = i;
                lst[i] = i;
            }
            else lst[i] = lst[i + 1];
        }
        if (first_one == -1) debil1();
        for (int l = 1; l + k - 1 <= n; l++) {
            int r = l + k - 1;
            if (frst[l - 1] == -1 && lst[r + 1] == -1) {
                debil1();
            }
            if (frst[l - 1] != -1 && lst[r + 1] != -1) {
                can_first = true;
            }
            else if (frst[l - 1] == -1) {
                if (last_one - lst[r + 1] + 1 > k) can_first = true;
            }
            else {
                if (frst[l - 1] - first_one + 1 > k) can_first = true;
            }
        }
    }
    if (can_first) draw();
    else debil2();
    return 0;
}