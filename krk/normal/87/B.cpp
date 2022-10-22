#include <iostream>
#include <map>
#include <string>
using namespace std;

int n;
map <string, int> type;

void getStat(string &s, int &st)
{
     st = 0;
     while (s.length() && s[0] == '&') {
           st--;
           s.erase(0, 1);
     }
     while (s.length() && s[s.length()-1] == '*') {
           st++;
           s.erase(s.length()-1, 1);
     }
}

int main()
{
    type["errtype"] = -1;
    type["void"] = 0;
    cin >> n;
    while (n--) {
          string s, A, B;
          int st;
          cin >> s;
          if (s == "typedef") {
                cin >> A >> B;
                getStat(A, st);
                if (type.find(A) == type.end()) type[B] = -1;
                else if (type[A] < 0 || type[A] + st < 0) type[B] = -1;
                else type[B] = type[A] + st;
          } else {
                 cin >> A;
                 getStat(A, st);
                 if (type.find(A) == type.end()) cout << "errtype\n";
                 else if (type[A] < 0 || type[A] + st < 0) cout << "errtype\n";
                 else {
                      st += type[A];
                      cout << "void";
                      while (st--) cout << "*";
                      cout << endl;
                 }
          }
    }
    return 0;
}