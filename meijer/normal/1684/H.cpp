#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t;
string s;
vector<pair<int,int>> ans;

int find(int n, int l) {
    while (1) {
        if (s[l-1] == '1')
            n--;
        if (n == 0)
            return l;
        l++;
    }
}

void solve(int l, int r, int n, int k) {
    if (k == n) {
        for (int i=l; i<=r; i++)
            ans.push_back({i, i});
        return;
    }

    if (n <= (3*k)/2) {
        int mid = find(1, l) + 1;
        ans.push_back({l, mid});
        if (mid != r) {
            if (s[mid-1] == '1') solve(mid+1, r, n-3, k-2);
            else solve(mid+1, r, n-2, k-1);
        }
        return;
    }

    if ((k == 10 && n == 16) || (k == 7 && n == 11)) {
        int mid = find(4,l);
        solve(l, mid, 8, 4);
        solve(mid+1, r, n-8, k-4);
        return;
    }

    if ((k == 4 && n == 8) || (k == 9 && n == 16)) {
        int mid = find(1, l);
        ans.push_back({l, mid+2});
        string substr = s.substr(mid-1,3);
        if (substr == "100") solve(mid+3, r, n-4, k-1);
        if (substr == "101") solve(mid+3, r, n-5, k-2);
        if (substr == "110") solve(mid+3, r, n-6, k-2);
        if (substr == "111") solve(mid+3, r, n-7, k-3);
        return;
    }

    int mid = find(k/2, l);
    solve(l, mid, n/2, k/2);
    solve(mid+1, r, n/2, k - k/2);
}

void solveFive() {
    int fir = find(1,1), las = find(5,1);
    if (las - fir == 4) {
        if (fir != 1) ans.push_back({1,fir-1});
        ans.push_back({fir, las-1});
        ans.push_back({las, las});
        if (las != s.size())
            ans.push_back({las+1, s.size()});
    } else {
        // 101 or 100
        int p = s.find("101")+1;
        if (p == 0)
            p = s.find("100")+1;
        for (int i=1; i<p; i++)
            ans.push_back({i, i});
        ans.push_back({p, p+2});
        for (int i=p+3; i<=s.size(); i++)
            ans.push_back({i, i});
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> s;
        ans.clear();

        int cnt = count(s.begin(), s.end(), '1');
        
        if (cnt == 0) {
            cout << -1 << '\n';
            cout << '\n';
            continue;
        }

        if (cnt == 5) {
            solveFive();
        } else {
            int nxt = 1;
            while (nxt < cnt)
                nxt *= 2;
            solve(1, s.size(), nxt, cnt);
        }

        cout << ans.size() << '\n';
        for (auto x : ans)
            cout << x.fi << " " << x.se << '\n';
        cout << '\n';
    }
}