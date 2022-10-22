#include <iostream>
#include <string>
using namespace std;

const string vowels = "aeiouyAEIOUY";

int main()
{
    int i;
    string s;
    getline(cin, s);
    for (i = s.length()-1; i >= 0; i--)
       if (s[i] != ' ' && s[i] != '?') break;
    if (vowels.find(s[i]) != string::npos) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}