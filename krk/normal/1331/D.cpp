#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin >> s;
    int md = int(s[int(s.length()) - 1] - '0') % 2;
    cout << md << endl;
    return 0;
}