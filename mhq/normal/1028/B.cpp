#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 120;
int n, m;
char a[maxN][maxN];
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    string s1;
    string s2;
    for (int i = 1; i <= 2000; i++) s1 += '1';
    for (int i = 1; i <= 1999; i++) s2 += '8';
    s2 += '9';
    cout << s1 << '\n' << s2;
    return 0;
}