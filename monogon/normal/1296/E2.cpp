
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
string s;
char c[N];
int color[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    int k = 0;
    for(int i = 0; i < n; i++) {
        int j = 0;
        for(; ; j++) {
            if(c[j] <= s[i]) {
                break;
            }
        }
        c[j] = s[i];
        color[i] = j + 1;
        k = max(k, j + 1);
    }
    cout << k << endl;
    for(int i = 0; i < n; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
}