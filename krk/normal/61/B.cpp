#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxl = 601;
const string signs = "-;_";

vector <string> str;

void Gets(string &s)
{
     char ss[Maxl];
     cin.getline(ss, Maxl, '\n');
     s = "";
     for (int i = 0; i < strlen(ss); i++)
        if (signs.find(ss[i]) == string::npos) {
                              if ('A' <= ss[i] && ss[i] <= 'Z') s += char(ss[i]-'A'+'a');
                              else s += ss[i];
        }
}

int main()
{
    int n;
    string a, b, c, s;
    Gets(a); Gets(b); Gets(c);
    str.push_back(a + b + c); str.push_back(a + c + b);
    str.push_back(b + a + c); str.push_back(b + c + a);
    str.push_back(c + a + b); str.push_back(c + b + a);
    cin >> n; cin.ignore();
    while (n--) {
    Gets(s);
          if (find(str.begin(), str.end(), s) != str.end()) cout << "ACC\n";
          else cout << "WA\n";
    }
    return 0;
}