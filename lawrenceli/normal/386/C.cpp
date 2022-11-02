#include <iostream>
#include <algorithm>
#include <ios>
#include <set>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 300100;

string s;
int n, freq[200];
ll ans[30];

set<char> st;

ll go(int sze) {
    int lt = 0, rt = 0, cnt = 0;
    ll ret = 0;
    memset(freq, 0, sizeof(freq));
    
    while (lt < n) {
        if (rt == n || cnt == sze + 1) {
            if (cnt == sze + 1) ret += rt - lt - 1;
            else ret += rt - lt;
            
            freq[s[lt]] --;
            if (freq[s[lt]] == 0) cnt--;
            lt++;
        } else {
            freq[s[rt]] ++;
            if (freq[s[rt]] == 1) cnt++;
            rt++;
        }
    }
    
    return ret;
}

int main() {
    ios :: sync_with_stdio(false);
    
    cin >> s; n = s.length();
    
    for (int i=0; i<s.length(); i++) st.insert(s[i]);
    
    cout << st.size() << '\n';
    
    for (int i=1; i<=st.size(); i++) ans[i] = go(i);
    
    for (int i=1; i<=st.size(); i++) cout << ans[i] - ans[i-1] << '\n';
    
    return 0;
}