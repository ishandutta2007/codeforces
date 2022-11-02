#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> s;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++) {
            int d = j-i;
            if (s[i] == '.' || s[j] == '.') continue;
            bool b = 1;
            for (int k=j+d; k<=j+3*d; k+=d) {
                if (k >= n) { b = 0; break; }
                if (s[k] == '.') b = 0;
            }
            if (b) {
                cout << "yes";
                return 0;
            }
        }
    cout << "no";
}