#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, ss = "";
    cin >> s;
    for (int i = 0; i < s.length(); i++)
       if (i == 0 || s[i] != '/' || s[i - 1] != '/') ss += s[i];
    while (ss.length() > 1 && ss[ss.length()-1] == '/') ss.erase(ss.length()-1, 1);
    cout << ss << endl;
    return 0;
}