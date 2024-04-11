
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string s;
bool arr[10];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') {
            for(int j = 0; j < 10; j++) {
                if(!arr[j]) {
                    arr[j] = true;
                    break;
                }
            }
        }else if(s[i] == 'R') {
            for(int j = 9; j >= 0; j--) {
                if(!arr[j]) {
                    arr[j] = true;
                    break;
                }
            }
        }else {
            arr[s[i] - '0'] = false;
        }
    }
    for(int i = 0; i < 10; i++) {
        cout << (arr[i] ? '1' : '0');
    }
    cout << endl;
}