#include <iostream>
#include <string>
using namespace std;

const string word = "hello";

int main()
{
    int no = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
       if (s[i] == word[no]) {
                no++;
                if (no == word.length()) break;
       }
    if (no == word.length()) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}