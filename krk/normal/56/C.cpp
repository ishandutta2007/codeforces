#include <iostream>
#include <map>
#include <string>
using namespace std;

string info;
int res;

void Search(map <string, int> &M)
{
     string s = "";
     map <string, int> MM, MMM;
     while ('A' <= info[0] && info[0] <= 'Z') {
           s += info[0]; info.erase(0, 1);
     }
     if (info[0] == ':') {
                 do {
                     info.erase(0, 1);
                     MMM.clear();
                     Search(MMM);
                     for (map <string, int>::iterator it = MMM.begin(); it != MMM.end(); it++)
                        if (MM.count(it->first) == 0) MM[it->first] = it->second;
                        else MM[it->first] += it->second;
                 } while (info[0] == ',');
                 if (MM.count(s)) res += MM[s];
                 for (map <string, int>::iterator it = MM.begin(); it != MM.end(); it++)
                    if (M.count(it->first) == 0) M[it->first] = it->second;
                    else M[it->first] += it->second;
     }
     info.erase(0, 1);
     if (M.count(s) == 0) M[s] = 1;
     else M[s]++;
}

int main()
{
    cin >> info;
    map <string, int> M;
    Search(M);
    cout << res << endl;
    return 0;
}