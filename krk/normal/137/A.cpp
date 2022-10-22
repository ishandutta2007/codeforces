#include <iostream>
#include <string>
using namespace std;

string s;
int r;
int res;

int main()
{
    getline(cin, s); s += '.';
    for (int i = 0; i + 1 < s.length(); i++)
        if (++r == 5 || s[i] != s[i + 1]) { res++; r = 0; }
    cout << res << endl;
    return 0;
}