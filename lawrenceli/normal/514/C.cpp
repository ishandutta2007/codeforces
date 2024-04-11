#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 600100;
const int MULT = 31;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;

int n, m;
set<pii> st;
int pw1[MAXN], pw2[MAXN];

pii shash(string s) {
    pii ret = pii(0, 0);
    for (int i=0; i<s.length(); i++)
        ret.first = (ret.first+ll(s[i])*pw1[i]%MOD1)%MOD1, 
        ret.second = (ret.second+ll(s[i])*pw2[i]%MOD2)%MOD2;
    return ret;
}

int main() {
    pw1[0] = pw2[0] = 1;
    for (int i=1; i<MAXN; i++) {
        pw1[i] = ll(pw1[i-1])*MULT%MOD1;
        pw2[i] = ll(pw2[i-1])*MULT%MOD2;
    }
    
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        pii p = shash(s);
        
        for (int j=0; j<s.length(); j++)
            for (char c='a'; c<='c'; c++) if (s[j] != c)
                st.insert(pii((p.first+ll(c-s[j]+MOD1)*pw1[j]%MOD1)%MOD1, 
                              (p.second+ll(c-s[j]+MOD2)*pw2[j]%MOD2)%MOD2));
    }
    for (int i=0; i<m; i++) {
        string s; cin >> s;
        cout << (st.count(shash(s)) ? "YES\n" : "NO\n");
    }
}