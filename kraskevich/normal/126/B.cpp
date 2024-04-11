#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> z(n, 0);
    z[0] = n;
    for(int i = 1, l = 0, r = 0; i < n; ++i) {
            if(i <= r)
                 z[i] = min(z[i - l], r - i + 1);
            while(i + z[i] < n && s[z[i]] == s[i + z[i]])
                    ++z[i];
            if(i + z[i] - 1 > r)
                 r = i + z[i] - 1, l = i;
    }
    vector<bool> was(n, false);
    string no = "Just a legend";
    int l = -1;
    vector<int> p(n, 0);
    for(int i = 1, k = 0; i < n; ++i) {
            while(k > 0 && s[i] != s[k])
                    k = p[k - 1];
            if(s[i] == s[k])
                    ++k;
            p[i] = k;
            if(i != n - 1)
                was[p[i]] = true;
    } 
    for(int i = 1; i < s.length(); ++i)
            if(i + z[i] == n && was[z[i]]) {
                 l = i;
                 break;
            }
    if(l < 0)
         cout << no;
    else
        for(int i = l; i < s.length(); ++i)
                cout << s[i];
    return 0;
}