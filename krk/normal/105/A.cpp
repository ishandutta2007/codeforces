#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m, k1;
map <string, int> M;

int main()
{
    double k;
    cin >> n >> m >> k;
    k1 = int(100.0 * k + 0.4);
    string skill;
    int lvl;
    while (n--) {
          cin >> skill >> lvl;
          int nlvl = lvl * k1 / 100;
          if (nlvl >= 100) M[skill] = nlvl;
    }
    while (m--) {
          cin >> skill;
          if (M.find(skill) == M.end()) M[skill] = 0; 
    }
    cout << M.size() << endl;
    for (map <string, int>::iterator it = M.begin(); it != M.end(); it++)
       cout << it->first << " " << it->second << endl;
    return 0;
}