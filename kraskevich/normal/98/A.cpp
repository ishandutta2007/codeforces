#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<char> c(6);
    for(int i = 0; i < 6; ++i)
            cin >> c[i];
    sort(c.begin(), c.end());
    int cur = 0;
    vector<int> t;
    string s = "";
    for(int i = 0; i < 6; ++i) {
            ++cur;
            if(i == 5 || c[i] != c[i + 1]) {
                    t.push_back(cur);
                    cur = 0;
            }
            
    }
    sort(t.begin(), t.end());
    for(int i = 0; i < t.size(); ++i)
            s += char('0' + t[i]);
    //cout << s << endl; 
    if(s == "6" || s == "15")
         cout << 1;
    if(s == "24" || s == "33" || s == "114")
         cout << 2;
    if(s == "123")
         cout << 3;
    if(s == "1113")
         cout << 5;
    if(s == "222")
         cout << 6;
    if(s == "1122")
         cout << 8;
    if(s == "11112")
         cout << 15;
    if(s == "111111")
         cout << 30;
    cin >> s;
    return 0;
}