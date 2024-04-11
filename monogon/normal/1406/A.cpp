
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        map<int, int> ma;
        rep(i, 0, n) {
            int a;
            cin >> a;
            ma[a]++;
        }
        int idx1 = 0, idx2 = 0;
        while(ma[idx1] > 0) idx1++;
        while(ma[idx2] > 1) idx2++;
        cout << idx1 + idx2 << '\n';
    }
}