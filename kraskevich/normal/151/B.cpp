#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int taxi = 0, girl = 2, pizza = 1;

int Type(string s) {
    vector<char> c;
    for(int i = 0; i < s.length(); ++i)
            if(s[i] != '-')
                    c.push_back(s[i]);
    bool tx = true;
    for(int i = 1; i < 6; ++i)
            if(c[i] != c[i - 1])
                    tx = false;
    if(tx)
          return taxi;
    bool pz = true;
    for(int i = 1; i < 6; ++i)
            if(c[i] >= c[i - 1])
                    pz = false;
    if(pz)
          return pizza;
    return girl;
}

int main() {
    int n;
    cin >> n;
    string s[n];
    int tx[n], pz[n], gr[n], maxT = 0, maxP = 0, maxG = 0;
    for(int num = 0; num < n; ++num) {
            tx[num] = pz[num] = gr[num] = 0;
            int k;
            cin >> k;
            cin >> s[num];
            for(int i = 0; i < k; ++i) {
                    string t;
                    cin >> t;
                    int type = Type(t);
                    if(type == taxi)
                            tx[num]++;
                    if(type == pizza)
                            pz[num]++;
                    if(type == girl)
                            gr[num]++;
            }
            maxT = max(maxT, tx[num]);
            maxP = max(maxP, pz[num]);
            maxG = max(maxG, gr[num]);
    }
    bool printed = false;
    cout << "If you want to call a taxi, you should call:"; 
    for(int i = 0; i < n; ++i)
            if(tx[i] == maxT) {
                     if(printed)
                                cout << ", " << s[i];
                     else
                         cout << " " << s[i];
                     printed = true;
            }
    cout << '.' << endl;
    printed = false;
    cout << "If you want to order a pizza, you should call:"; 
    for(int i = 0; i < n; ++i)
            if(pz[i] == maxP) {
                     if(printed)
                                cout << ", " << s[i];
                     else
                         cout << " " << s[i];
                     printed = true;
            }
    cout << '.' << endl;
    printed = false;
    cout << "If you want to go to a cafe with a wonderful girl, you should call:"; 
    for(int i = 0; i < n; ++i)
            if(gr[i] == maxG) {
                     if(printed)
                                cout << ", " << s[i];
                     else
                         cout << " " << s[i];
                     printed = true;
            }
    cout << '.';
    cin >> n;
    return 0;
}