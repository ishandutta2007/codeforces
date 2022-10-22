#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int res;

int main()
{
    cin >> a >> b;
    a = string(b.length(), '.') + a + string(b.length(), '.');
    res = b.length();
    for (int i = 0; i + b.length() <= a.length(); i++) {
        int cand = 0;
        for (int j = 0; j < b.length(); j++)
            cand += a[i + j] != b[j];
        res = min(res, cand);
    }
    cout << res << endl;
    return 0;
}