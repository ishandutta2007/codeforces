
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while(n--) {
        cin >> str;
        int k = str.length();
        ll sum = 0;
        bool z = false;
        ll even = 0;
        for(int i = 0; i < k; i++) {
            sum += (str[i] - '0');
            if(str[i] == '0') z = true;
            if((str[i] - '0') % 2 == 0) even++;
        }
        if(sum % 3 == 0 && z && even >= 2) {
            cout << "red" << endl;
        }else {
            cout << "cyan" << endl;
        }
    }
}