#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
       if (s[i] == ' ' && !('0' <= s[i-1] && s[i-1] <= '9' && '0' <= s[i+1] && s[i+1] <= '9')) {
                s.erase(i, 1); i--;
       }
    for (int i = 0; i < s.length()-1; i++)
       if (s[i] == ',') s.insert(i+1, " ");
    int st;
    if (s.find_first_of("...") == 0) st = 3;
    else st = 1;
    for (int i = st; i < s.length(); )
       if (s.find_first_of("...", i) == i)
          if (s[i-1] != ' ') {
                     s.insert(i, " ");
                     i += 4;
          } else i += 3;
       else i++;
    for (int i = 0; i < s.length(); i++)
       cout << s[i];
    cout << endl;
    return 0;
}