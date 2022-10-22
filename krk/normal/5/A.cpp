#include <iostream>
#include <set>
#include <string>
using namespace std;

typedef long long ll;

set <string> S;
ll res;

int main()
{
    string s;
    while (getline(cin, s))
       if (s[0] == '+') S.insert(s.substr(1, s.length()-1));
       else if (s[0] == '-') S.erase(s.substr(1, s.length()-1));
       else res += (s.length()-1-s.find(':')) * S.size();
    cout << res << endl;
    return 0;
}