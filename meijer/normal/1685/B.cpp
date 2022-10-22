#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t, a, b, c, d;
string s;
int n;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        cin >> s; n = s.size();
        int tota = 0;
        int totb = 0;
        for (char c : s)
            tota += c=='A', totb += c=='B';
        if (tota != a + c + d || totb != b + c + d) {
            cout <<"NO"<<endl;
            continue;
        }

        int free = 0;
        priority_queue<int,vector<int>,greater<int>> forc, ford;

        int i=0;
        while (i < n) {
            int start = i;
            while (start+1 < n && s[start+1] == s[start])
                start++;
            int end = start;
            while (end+1 < n && s[end+1] != s[end])
                end++;
            int len = end - start + 1;
            if (len % 2) free += len/2;
            else {
                if (s[start] == 'A') forc.push(len/2);
                else ford.push(len/2);
            }
            i = end+1;
        }

        while (!forc.empty()) {
            int x = forc.top(); forc.pop();
            if (x <= c) c -= x;
            else free += x-1;
        }
        while (!ford.empty()) {
            int x = ford.top(); ford.pop();
            if (x <= d) d -= x;
            else free += x-1;
        }

        cout << (free >= c + d ? "YES" : "NO" )<< endl;
    }
}