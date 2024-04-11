#include <iostream>
#include <string>
#include <map>
using namespace std;

string s;
map <char, int> nums;

int main()
{
    int i;
    getline(cin, s);
    for (i = 0; i < s.length(); i++)
       if (s[i] != ' ')
          if (nums.count(s[i]) == 0) nums[s[i]] = 1;
          else nums[s[i]]++;
    getline(cin, s);
    for (i = 0; i < s.length(); i++)
       if (s[i] != ' ')
          if (nums.count(s[i]) == 0 || nums[s[i]] == 0) break;
          else nums[s[i]]--;
    if (i == s.length()) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}