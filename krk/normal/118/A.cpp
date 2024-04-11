#include <bits/stdc++.h>
using namespace std;

const string con = "aoeyui";

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
        if (con.find(s[i]) == string::npos)
            cout << "." << s[i];
    }
    cout << endl;
    return 0;
}