#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
using namespace std;

string s;
map <string, set <string> > fold;
map <string, int> folders;
map <string, int> fils;

void Calc(string pth, int &fol, int &fil)
{
     fil += fils[pth];
     for (set <string>::iterator it = fold[pth].begin(); it != fold[pth].end(); it++) {
         fol++;
         Calc(pth + "\\" + *it, fol, fil);
     }
}

void Test(char c, int &fol, int &fil)
{
     string d;
     stringstream ss;
     ss << c;
     ss >> d; d += ":";
     fol = fil = 0;
     int cfol, cfil;
     for (set <string>::iterator it = fold[d].begin(); it != fold[d].end(); it++) {
         cfol = cfil = 0;
         Calc(d + "\\" + *it, cfol, cfil);
         fol = max(fol, cfol); fil = max(fil, cfil);
     }
}

int main()
{
    while (cin >> s) {
          int pos = s.find_last_of("\\");
          if (fils.find(s.substr(0, pos)) == fils.end())
             fils[s.substr(0, pos)] = 1;
          else fils[s.substr(0, pos)]++;
          s.erase(pos);
          while (s.find_last_of("\\") != string::npos) {
                pos = s.find_last_of("\\");
                fold[s.substr(0, pos)].insert(s.substr(pos+1));
                s.erase(pos);
          }

    }
    int fol = 0, fil = 0;
    int curfol, curfil;
    for (char c = 'C'; c <= 'G'; c++) {
        Test(c, curfol, curfil);
        fol = max(fol, curfol); fil = max(fil, curfil);
    }
    cout << fol << " " << fil << endl;
    return 0;
}