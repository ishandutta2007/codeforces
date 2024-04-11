#include <bits/stdc++.h>
using namespace std;

char s[105], t[105];

int main() {
    cin >> s >> t;
    int n = strlen(s);
    for (int i=n-1; i>=0; i--)
        if (s[i] != 'z') {
            s[i]++;
            for (i++; i<n; i++) s[i] = 'a';
            break;
        }
    
    for (int i=0; i<n; i++)
        if (s[i] != t[i]) {
            cout << s;
            return 0;
        }
    cout << "No such string";
}