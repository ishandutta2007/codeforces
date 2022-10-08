
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        while(!s.empty() && (s.back() - '0') % 2 == 0) {
            s.pop_back();
        }
        if(s.empty()) cout << -1 << endl;
        else {
            int i = 0;
            for(; i < (int) s.size() - 1; i++) {
                if((s[i] - '0') % 2 == 1) {
                    break;
                }
            }
            if(i == (int) s.size() - 1) {
                cout << -1 << endl;
            }else {
                int sum = 0;
                for(int j = 0; j < (int) s.size(); j++) {
                    sum += (s[j] - '0');
                }
                if(sum % 2 == 1) s.erase(s.begin() + i);
                while(s.front() == '0') s.erase(s.begin());
                cout << s << endl;
            }
        }
    }
}