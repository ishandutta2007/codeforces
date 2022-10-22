#include <iostream>
#include <map>
#include <string>
using namespace std;

map <string, int> goals;

int main()
{
    int i, n, mx = 0;
    string s, win;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> s;
        if (goals.count(s) == 0) goals[s] = 1;
        else goals[s]++;
    }
    for (map <string, int>::iterator it = goals.begin(); it != goals.end(); it++)
       if (it->second > mx) {
                      mx = it->second;
                      win = it->first;
       }
    cout << win << endl;
    return 0;
}