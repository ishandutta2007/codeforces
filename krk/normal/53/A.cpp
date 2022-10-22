#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector <string> dict;

int main()
{
    string s, ss;
    int i;
    cin >> s >> n;
    while (n--) {
          cin >> ss;
          dict.push_back(ss);
    }
    sort(dict.begin(), dict.end());
    for (i = 0; i < dict.size(); i++)
       if (dict[i].find(s) == 0) {
                           cout << dict[i] << endl;
                           break;
       }
    if (i == dict.size()) cout << s << endl;
    return 0;
}