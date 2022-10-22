#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
    cin >> s;
    int i, lst = -2;
    for (i = 0; i < s.length(); i++)
       if (s[i] == '@') if (lst >= i-2) break;
                        else lst = i;
    if (lst == -2 || i < s.length() || s[s.length()-1] == '@') cout << "No solution\n";
    else {
         while (s.find("@") != s.find_last_of("@")) {
               cout << s.substr(0, s.find("@")+2) << ",";
               s.erase(0, s.find("@")+2);
         }
         cout << s << endl;
    }
    return 0;
}