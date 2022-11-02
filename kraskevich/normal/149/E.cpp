#include <iostream>
#include <string>
#include <vector>
using namespace std;

string rev(string s) {
       string res = "";
       for(int i = s.length() - 1; i >= 0; --i)
               res += s[i];
       return res;
}

vector<int> p_func(string s) {
            int n = s.length(), k = 0;
            vector<int> p(n, 0);
            for(int i = 1; i < n; ++i) {
                    while(s[i] != s[k] && k > 0)
                               k = p[k - 1];
                    if(s[i] == s[k])
                            ++k;
                    p[i] = k;
            }
            return p;
}

int main() {
    string s;
    
    cin >> s;
    
    int n, res = 0, len = s.length();
    
    cin >> n;
    
    for(int j = 0; j < n; ++j) {
            bool found = false;
            string patt;
            cin >> patt;
            vector<int> p1, p;
            int m = patt.length();
            if(m == 1)
                 continue;
            vector<int> suff(m + 1, -1);
            vector<int> pref(m + 1, 1000 * 1000);
            string q = patt + '#' + s;
            p = p_func(q);
            q = rev(patt) + '#' + rev(s);
            p1 = p_func(q);
            for(int i = m + 1; i < q.length(); ++i) 
                    for(int k = p[i]; k <= p[i]; ++k)
                            pref[k] = min(pref[k], i - m - 1);
            for(int i = m + 1; i < q.length(); ++i)
                    for(int k = p1[i]; k <= p1[i]; ++k)
                            suff[k] = max(suff[k], (int)((int)len - (i - m))); 
            int mx = suff[m];
            for(int i = m - 1; i >= 0; --i) {
                    suff[i] = max(suff[i], mx);
                    mx = max(suff[i], mx);
            }
            int mn = pref[m];
            for(int i = m - 1; i >= 0; --i) {
                    pref[i] = min(pref[i], mn);
                    mn = min(pref[i], mn);
            }
            for(int i = 0; i <= m; ++i)
                  if(suff[i] > pref[m - i]) {
                             found = true;
                             break;
                  }
            
            res += found;
    }
    
    cout << res;
    
    return 0;
}