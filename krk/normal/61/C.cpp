#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef long long ll;

const string let = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int a;
string c;

ll ToDec(const string &s)
{
    ll res = 0;
    for (int i = 0; i < s.length(); i++)
       res = a * res + let.find(s[i]);
    return res;
}

int ToInt(const string &s)
{
    int num;
    stringstream ss(s);
    ss >> num;
    return num;
}

string Conv(ll lft, int bas)
{
    if (lft == 0) return "0";
    else {
         string s = "";
         if (lft / bas) s += Conv(lft/bas, bas);
         s += let[lft % bas];
         return s;
    }
}

string Change(ll lft)
{
    string s = "";
    while (lft >= 1000) { lft -= 1000; s += "M"; }
    if (lft >= 900) { lft -= 900; s += "CM"; }
    while (lft >= 500) { lft -= 500; s += "D"; }
    if (lft >= 400) { lft -= 400; s += "CD"; }
    while (lft >= 100) { lft -= 100; s += "C"; }
    if (lft >= 90) { lft -= 90; s += "XC"; }
    while (lft >= 50) { lft -= 50; s += "L"; }
    if (lft >= 40) { lft -= 40; s += "XL"; }
    while (lft >= 10) { lft -= 10; s += "X"; }
    if (lft >= 9) { lft -= 9; s += "IX"; }
    while (lft >= 5) { lft -= 5; s += "V"; }
    if (lft >= 4) { lft -= 4; s += "IV"; }
    while (lft >= 1) { lft--; s += "I"; }
    return s;
}

int main()
{
    string bb;
    cin >> a >> bb >> c;
    if (bb == "R") cout << Change(ToDec(c)) << endl;
    else cout << Conv(ToDec(c), ToInt(bb)) << endl;
    return 0;
}