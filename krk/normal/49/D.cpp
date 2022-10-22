#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, mina, minb;
string a, b, s;

int main()
{
    int i;
    cin >> n;
    cin >> s;
    a = "0"; b = "1";
    for (i = 1; i < n; i++) {
        if (a[i-1] == '0') a += "1";
        else a += "0";
        if (b[i-1] == '0') b += "1";
        else b += "0";
    }
    for (i = 0; i < n; i++) {
        if (s[i] != a[i]) mina++;
        if (s[i] != b[i]) minb++;
    }
    cout << min(mina, minb) << endl;
    return 0;
}