#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const string dig = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string a, b;
bool was;

int minSys(const string &s)
{
    int mx = 2;
    for (int i = 0; i < s.length(); i++) mx = max(mx, int(dig.find(s[i])) + 1);
    return mx;
}

bool Pos(int rad)
{
     int sum = 0;
     for (int i = 0; i < a.length() && sum < 24; i++)
         sum = sum * rad + dig.find(a[i]);
     if (sum >= 24) return false;
     sum = 0;
     for (int i = 0; i < b.length() && sum < 60; i++)
         sum = sum * rad + dig.find(b[i]);
     return sum < 60;
}

int main()
{
    getline(cin, a, ':'); getline(cin, b);
    if (Pos(60)) cout << "-1\n";
    else {
         for (int i = max(minSys(a), minSys(b)); i < 60; i++)
             if (Pos(i)) {
                         if (was) cout << " ";
                         was = true;
                         cout << i;
             }
         if (!was) cout << "0";
         cout << endl;
    }
    return 0;
}