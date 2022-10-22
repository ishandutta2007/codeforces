#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

map <char, int> heav;
vector < pair<int, char> > ans;

int main()
{
    string s;
    int i;
    while (getline(cin, s))
       if (s[1] == '>') {
                if (heav.count(s[0]) == 0) heav[s[0]] = 1;
                else heav[s[0]]++;
                if (heav.count(s[2]) == 0) heav[s[2]] = 0;
       } else {
              if (heav.count(s[2]) == 0) heav[s[2]] = 1;
              else heav[s[2]]++;
              if (heav.count(s[0]) == 0) heav[s[0]] = 0;
       }
    for (map <char, int>::iterator it = heav.begin(); it != heav.end(); it++)
       ans.push_back(make_pair(it->second, it->first));
    sort(ans.begin(), ans.end());
    for (i = 0; i < ans.size(); i++)
       if (ans[i].first != i) break;
    if (i < ans.size()) cout << "Impossible\n";
    else {
         for (i = 0; i < ans.size(); i++)
            cout << ans[i].second;
         cout << endl;
    }
    return 0;
}