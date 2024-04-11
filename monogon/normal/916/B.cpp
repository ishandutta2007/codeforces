
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

ll n;
int k;
map<int, int> cnt;

// find smallest possible y value with priority queue
// to find lexicographically maximum, use priority queue until top element

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int sum = 0;
    rep(i, 0, 60) {
        if((n >> i) & 1) {
            cnt[i]++;
            sum++;
        }
    }
    if(sum > k) {
        cout << "No\n";
        return 0;
    }
    while(sum < k) {
        int x = prev(cnt.end())->first;
        cnt[x]--;
        cnt[x - 1] += 2;
        sum++;
        if(cnt[x] == 0) cnt.erase(x);
    }
    int ans = prev(cnt.end())->first;
    sum = 0;
    cnt.clear();
    rep(i, 0, 60) {
        if((n >> i) & 1) {
            cnt[i]++;
            sum++;
        }
    }
    while(sum < k) {
        int x = prev(cnt.end())->first;
        if(x <= ans) {
            x = cnt.begin()->first;
        }
        cnt[x]--;
        cnt[x - 1] += 2;
        if(cnt[x] == 0) cnt.erase(x);
        sum++;
    }
    cout << "Yes\n";
    while(k--) {
        int x = prev(cnt.end())->first;
        cout << x << ' ';
        cnt[x]--;
        if(cnt[x] == 0) cnt.erase(x);
    }
    cout << '\n';
}