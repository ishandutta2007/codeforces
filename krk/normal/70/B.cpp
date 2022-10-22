#include <iostream>
#include <string>
using namespace std;

int n, ans, pnt;
string tex, mess, sen;
bool imp;

bool Send()
{
     if (mess.length() == 0|| mess.length() > n) return false;
     ans++;
     mess = "";
     return true;
}

bool ReadSen()
{
     sen = "";
     while (pnt < tex.size() && tex[pnt] != '.' && tex[pnt] != '?' && tex[pnt] != '!')
        sen += tex[pnt++];
     if (pnt < tex.size()) sen += tex[pnt++];
     return sen.length();
}

int main()
{
    cin >> n; getline(cin, tex);
    getline(cin, tex);
    while (ReadSen() && !imp) {
          if (mess.size() + sen.size() <= n) mess += sen;
          else { imp = !Send(); while (sen.length() && sen[0] == ' ') sen.erase(0, 1); mess += sen; }
    }
    imp = imp || !Send();
    if (imp) cout << "Impossible\n";
    else cout << ans << endl;
    return 0;
}