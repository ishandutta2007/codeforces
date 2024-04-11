#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int i;
string s;
vector <int> ans;

void Search(int lvl)
{
    if (lvl == ans.size()) ans.push_back(0);
    for (; i < s.length(); i++)
       if (i + 7 <= s.length() && s.substr(i, 7) == "<table>") { i++; Search(ans.size()); }
       else if (i + 8 <= s.length() && s.substr(i, 8) == "</table>") { i++; return; }
       else if (i + 4 <= s.length() && s.substr(i, 4) == "<td>") ans[lvl]++;
}

int main()
{
    int i, lvl = 0;
    string ss;
    while (cin >> ss) s += ss;
    Search(-1);
    sort(ans.begin(), ans.end());
    for (i = 0; i < ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    if (ans.size()) cout << endl;
    return 0;
}