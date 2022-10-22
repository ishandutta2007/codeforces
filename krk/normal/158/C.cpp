#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int n;
string s;
vector <string> pth;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "cd") {
            cin >> s;
            if (s[0] == '/') { pth.clear(); s.erase(0, 1); }
            if (s.length() == 0) continue;
            s += "/";
            while (s.length()) {
                int pos = s.find('/');
                string nam = s.substr(0, pos);
                if (nam == "..") pth.pop_back();
                else pth.push_back(nam);
                s.erase(0, pos + 1);
            }
        } else {
            for (int i = 0; i < pth.size(); i++) cout << "/" << pth[i];
            cout << "/\n";
        }
    }
    return 0;
}