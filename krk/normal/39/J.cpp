#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int Maxn = 1000005;

string a, b;
int l, r;

int main()
{
    getline(cin, a); getline(cin, b);
    r = a.length() - 1;
    while (r > 0 && a[r] == b[r - 1]) r--;
    l = 0;
    while (l < b.length() && a[l] == b[l]) l++;
    int res = l - r + 1;
    if (res <= 0) cout << "0\n";
    else {
         cout << res << endl;
         for (int i = r; i <= l; i++)
             cout << i + 1 << (i + 1 <= l? " ": "\n");
    }
    return 0;
}