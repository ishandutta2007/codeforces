
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e6 + 5, M = 1e9 + 7;
int n, k;
ll pow2[N];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pow2[0] = 1;
    rep(i, 1, N) {
        pow2[i] = (2 * pow2[i - 1]) % M;
    }
    cin >> n >> k >> s;
    deque<int> B(k - 1, 0), W(k, 0);
    B.push_front(1);
    ll ans = 0, sumB = 1, sumW = 0;
    int idxB = 1, idxW = 1;
    int x = 0;
    for(char c : s) if(c == 'X') x++;
    for(char c : s) {
        if(c == 'B') {
            B.push_front(0);
            idxB++;
            int back = 0;
            if(idxB > k) {
                back = B.back();
            }
            B.pop_back();
            sumB = (sumB - back) % M;
            sumW = (sumW + back) % M;
            idxW = 1;
            W.push_front(sumW);
            W.pop_back();
        }else if(c == 'W') {
            idxB = 1;
            B.push_front(sumB);
            B.pop_back();
            W.push_front(0);
            idxW++;
            int back = 0;
            if(idxW > k) {
                back = W.back();
            }
            W.pop_back();
            ans = (ans + back * pow2[x]) % M;
            sumW = (sumW - back) % M;
        }else {
            x--;
            B.push_front(sumB);
            idxB++;
            sumB = (sumB + sumB) % M;
            int back = 0;
            if(idxB > k) {
                back = B.back();
            }
            B.pop_back();
            sumB = (sumB - back) % M;
            W.push_front((back + sumW) % M);
            sumW = (sumW + back + sumW) % M;
            idxW++;
            back = 0;
            if(idxW > k) {
                back = W.back();
            }
            W.pop_back();
            ans = (ans + back * pow2[x]) % M;
            sumW = (sumW - back) % M;
        }
        assert(sz(B) == k);
        assert(sz(W) == k);
    }
    cout << (ans + M) % M << '\n';
}