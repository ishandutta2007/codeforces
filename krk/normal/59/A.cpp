#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
    int low = 0, upp = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
       if ('a' <= s[i] && s[i] <= 'z') low++;
       else upp++;
    if (low >= upp) {
       for (int i = 0; i < s.length(); i++)
          if ('A' <= s[i] && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
    } else for (int i = 0; i < s.length(); i++)
              if ('a' <= s[i] && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
    cout << s << endl;
    return 0;
}