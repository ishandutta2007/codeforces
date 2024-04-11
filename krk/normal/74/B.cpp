#include <iostream>
#include <string>
using namespace std;

int n, m, k, ax;

int main()
{
    string s;
    cin >> n >> k >> m;
    cin >> s >> s;
    if (s == "head") ax = -1;
    else ax = 1;
    cin >> s;
    int i;
    for (i = 0; i < s.length(); i++) {
        m += ax;
        if (m == 0) {
              ax = 1; m = 2;
        } else if (m == n + 1) {
               ax = -1; m = n - 1;
        }
        if (m == k && (k + ax == 0 || k + ax == n + 1) && s[i] == '0') break;
        if (s[i] == '1') {
                 if (m == 1) k = n;
                 else if (m == n) k = 1;
                 else if (ax == 1) k = 1;
                 else if (ax == -1) k = n;
        } else if (m == k) k += ax;
    }
    if (i < s.length()) cout << "Controller " << i + 1 << endl;
    else cout << "Stowaway\n";
    return 0;
}