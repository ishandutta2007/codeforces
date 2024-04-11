
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
        vector<string> s(3);
        cin >> n >> s[0] >> s[1] >> s[2];
        n *= 2;
        string book;
        vi p(3, 0);
        while(*max_element(all(p)) < n) {
            vi cnt(2, 0);
            rep(i, 0, 3) cnt[s[i][p[i]] - '0']++;
            int best = (cnt[0] > cnt[1] ? 0 : 1);
            rep(i, 0, 3) if(s[i][p[i]] - '0' == best) p[i]++;
            book.push_back(best + '0');
        }
        vector<pii> wtf;
        rep(i, 0, 3) wtf.push_back({p[i], i});
        sort(all(wtf));
        int idx = wtf[1].second;
        while(p[idx] < n) {
            book.push_back(s[idx][p[idx]]);
            p[idx]++;
        }
        while((int) book.length() < 3 * n / 2) book.push_back('0');
        cout << book << '\n';
    }
}