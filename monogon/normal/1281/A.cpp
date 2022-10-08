
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        switch(s.back()) {
            case 'o':
                cout << "FILIPINO" << endl;
                break;
            case 'u':
                cout << "JAPANESE" << endl;
                break;
            case 'a':
                cout << "KOREAN" << endl;
        }
    }
}