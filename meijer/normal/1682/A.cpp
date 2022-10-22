
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        string s; cin >> s;
        if (n ==2) {
            cout <<2 << endl;
        } else if(n%2) {
            int i = 0;
            while (s[n/2-1-i] == s[n/2]) i++;
            cout << i*2+1 << endl;
        } else {
            int i = 0;
            while (s[n/2-1-i] == s[n/2]) i++;
            cout << i*2 << endl;
        }
    }
}