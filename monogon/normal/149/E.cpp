
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

const int N = 2e5 + 5;
int n, m, k, kmp[N], kmp2[N];
string s, t;

void makekmp(string &s, int *kmp) {
    int n = s.length();
    int i = 1, j = 0;
    while(i < n) {
        if(s[i] == s[j]) kmp[i++] = ++j;
        else if(j == 0) kmp[i++] = 0;
        else j = kmp[j - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> m;
    n = s.length();
    int cnt = 0;
    rep(it, 0, m) {
        cin >> t;
        k = t.length();
        if(k == 1) continue;
        string s1 = t + "$" + s;
        string s2 = s + "$" + t;
        reverse(all(s2));
        makekmp(s1, kmp);
        makekmp(s2, kmp2);
        rep(i, 1, n + 1) {
            kmp[k + i] = max(kmp[k + i], kmp[k + i - 1]);
            kmp2[k + i] = max(kmp2[k + i], kmp2[k + i - 1]);
        }
        rep(i, 0, n + 1) {
            if(kmp[k + i] + kmp2[k + n - i] >= k) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << '\n';
}