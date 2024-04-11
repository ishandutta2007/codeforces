#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s;

int main()
{
    int i, j, tig = 0, hams = 0, best;
    cin >> n >> s;
    best = n;
    for (i = 0; i < s.length(); i++)
       if (s[i] == 'T') tig++;
    for (i = 0; i < s.length(); i++) {
        hams = 0;
        for (j = i; j < i + tig; j++)
           if (s[j % s.length()] == 'H') hams++;
        best = min(best, hams);
    }
    cout << best << endl;
    return 0;
}