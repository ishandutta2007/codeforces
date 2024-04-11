#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

vector<int> pos;
string s;
string t;
int n, m;

bool can(int cnt) {
    vector<bool> del(n);
    for (int i = 0; i < cnt; i++)
        del[pos[i]] = true;
    string cur;
    for (int i = 0; i < n; i++)
        if (!del[i])
            cur += s[i];
    int ptr = 0;
    int cur_n = cur.length();
    for (int i = 0; i < m; i++) {
        while (ptr < cur_n && cur[ptr] != t[i])
            ptr++;
        if (ptr == cur_n)
            return false;
        ptr++;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> s >> t;
    n = s.length();
    m = t.length();
    int l = 0;
    int r = n;
    pos.resize(n);
    for (int& x : pos) {
        cin >> x;
        --x;
    }
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (can(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
}