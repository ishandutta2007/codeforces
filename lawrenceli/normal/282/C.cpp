#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

string a, b;
bool f[4];

int main() {
    cin >> a >> b;
    if (a.length() != b.length()) {
        printf("NO\n"); return 0;
    }
    for (int i=0; i<a.length(); i++) f[a[i]-'0'] = 1;
    for (int i=0; i<b.length(); i++) f[b[i]-'0'+2] = 1;
    if (!f[1] && f[3]) printf("NO\n");
    else if (f[1] && !f[3]) printf("NO\n");
    else printf("YES\n");
}