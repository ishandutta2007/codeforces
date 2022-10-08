
#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

const int N = 1e4 + 5;
int n;
int p[N];

int ask(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    int ans;
    cin >> ans;
    if(ans == -1) exit(0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int idx = 1;
    rep(i, 2, n + 1) {
        int A = ask(idx, i);
        int B = ask(i, idx);
        if(A > B) {
            p[idx] = A;
            idx = i;
        }else {
            p[i] = B;
        }
    }
    p[idx] = n;
    cout << "! ";
    rep(i, 1, n + 1) cout << p[i] << ' ';
    cout << endl;
}