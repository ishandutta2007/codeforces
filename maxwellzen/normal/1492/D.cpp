#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int a, b, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> k;
    if (k>a+b-2 && k>0) {cout << "No\n"; return 0;}
    if (b<2 && k>0) {cout << "No\n"; return 0;}
    if (a<1 && k>0) {cout << "No\n"; return 0;}
    cout << "Yes\n";
    string x, y;
    for (int i = 0; i < b; i++) x += "1";
    for (int i = 0; i < a; i++) x += "0";
    y = x;
    if (k > 0) {
        int l = 1, r;
        if (k < b - 1) l = b - k;
        r = l + k;
        y[l] = '0';
        y[r] = '1';
    }
    cout << x << '\n' << y << '\n';
}