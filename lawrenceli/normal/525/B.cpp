#include <bits/stdc++.h>
using namespace std;

char s[200100], t[200100];
int n, m, add[200100];

int main() {
    cin >> s; n = strlen(s);
    cin >> m;
    for (int i=0; i<m; i++) {
        int a; cin >> a; a--;
        add[a]++, add[n-a]--;
    }
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += add[i];
        if (sum%2 == 0) t[i] = s[i];
        else t[i] = s[n-i-1];
    }
    cout << t;
}