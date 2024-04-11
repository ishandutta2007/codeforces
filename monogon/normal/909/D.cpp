
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

// group by components of colors

struct comp {
    char c;
    int cnt;
    comp(char c, int cnt): c(c), cnt(cnt) {}
};
int n;
string s;
vector<comp> ve;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    int i = 0;
    while(i < n) {
        int j = i;
        while(j < n && s[i] == s[j]) j++;
        ve.emplace_back(s[i], j - i);
        i = j;
    }
    int it = 0;
    while(sz(ve) > 1) {
        int k = sz(ve);
        rep(i, 0, k - 1) {
            ve[i].cnt--;
            ve[i + 1].cnt--;
        }
        vector<comp> v2;
        rep(i, 0, k) {
            if(ve[i].cnt <= 0) continue;
            if(v2.empty() || v2.back().c != ve[i].c) {
                v2.push_back(ve[i]);
            }else {
                v2.back().cnt += ve[i].cnt;
            }
        }
        ve = v2;
        it++;
    }
    cout << it << '\n';
}