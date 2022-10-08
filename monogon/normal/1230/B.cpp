
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, k;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> S;
    if(n == 1 && k >= 1) {
        cout << "0" << endl;
        return 0;
    }
    int j = 0;
    for(int i = 0; i < n && j < k; i++) {
        if(i == 0 && S[i] != '1') {
            S[i] = '1';
            j++;
        }else if(i > 0 && S[i] != '0') {
            S[i] = '0';
            j++;
        }
    }
    cout << S << endl;
}