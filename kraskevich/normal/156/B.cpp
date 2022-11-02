#include <iostream>
using namespace std;

int strtoint(string s) {
    int res = 0;
    for(int i = 1; i < s.length(); ++i)
            res = res * 10 + s[i] - '0';
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    char c[n]; int num[n], yes[n], no[n], allno = 0;
    for(int i = 0; i < n; ++i)
            yes[i] = no[i] = 0;
    for(int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            c[i] = s[0], num[i] = strtoint(s);
            --num[i];
            if(c[i] == '+') 
                    yes[num[i]]++;
            else {
                no[num[i]]++;
                allno++;
            }
    }
    bool can[n];
    int allcan = 0;
    for(int i = 0; i < n; ++i)
            can[i] = false;
    for(int i = 0; i < n; ++i)
            if(yes[i] + (allno - no[i]) == m) {
                      can[i] = true;
                      ++allcan;
            }
    for(int i = 0; i < n; ++i) {
            bool tr = false, lie = false;
            if(c[i] == '-') {
                    if(can[num[i]])
                                   lie = true;
                    if(allcan > 1 || allcan == 1 && !lie)
                              tr = true;
            }
            if(c[i] == '+') {
                    if(can[num[i]])
                                   tr = true;
                    if(allcan > 1 || allcan == 1 && !tr)
                              lie = true;
            }
            if(tr && lie)
                  cout << "Not defined" << endl;
            if(tr && !lie)
                  cout << "Truth" << endl;
            if(lie && !tr)
                   cout << "Lie" << endl;
    }
    cin >> n;
    return 0;
}