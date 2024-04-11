#include <bits/stdc++.h>
using namespace std;

char s[300100];
int n, m, num;

int main() {
cin >> n >> m >> s;
for (int i=0; i<n-1; i++)
if (s[i] == '.' && s[i+1] == '.') num++;

for (int i=0; i<m; i++) {
int k; char c;
cin >> k >> c;
k--;
if (s[k] == '.' && c != '.') {
if (k>0 && s[k-1] == '.') num--;
if (k<n-1 && s[k+1] == '.') num--;
} else if (s[k] != '.' && c == '.') {
if (k>0 && s[k-1] == '.') num++;
if (k<n-1 && s[k+1] == '.') num++;
}
s[k] = c;
cout << num << '\n';
}
}