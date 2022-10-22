#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

string t;
string s;
int my[Maxn];

int main()
{
    cin >> t;
    s = t;
    int mult = 1;
    for (int z = 0; z < 3; z++) {
        for (int i = 0; i < t.length(); i++)
            s[i] = i / mult % 26 + 'a';
        cout << "? " << s << endl; fflush(stdout);
        cin >> s;
        for (int i = 0; i < t.length(); i++)
            my[i] += int(s[i] - 'a') * mult;
        mult *= 26;
    }
    for (int i = 0; i < t.length(); i++)
        s[my[i]] = t[i];
    cout << "! " << s << endl; fflush(stdout);
    return 0;
}