#include <iostream>
#include <string>
using namespace std;

const int Maxl = 26;

int freq[Maxl];

int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) freq[s[i] - 'A']++;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) freq[s[i] - 'A']++;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) freq[s[i] - 'A']--;
    int i = 0;
    while (i < Maxl && freq[i] == 0) i++;
    if (i < Maxl) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}