
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

int t, n, a, b;
deque<int> v;
int p = 0, moves = 0;

void alice() {
    int sum = 0;
    moves += !v.empty();
    while(!v.empty() && sum <= p) {
        sum += v.front();
        v.pop_front();
    }
    p = sum;
    a += sum;
}
void bob() {
    int sum = 0;
    moves += !v.empty();
    while(!v.empty() && sum <= p) {
        sum += v.back();
        v.pop_back();
    }
    p = sum;
    b += sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        v.clear();
        cin >> n;
        while(n--) {
            cin >> a;
            v.push_back(a);
        }
        p = 0;
        a = b = 0;
        moves = 0;
        while(!v.empty()) {
            alice();
            bob();
        }
        cout << moves << ' ' << a << ' ' << b << '\n';
    }
}