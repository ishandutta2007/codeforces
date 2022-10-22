#include <iostream>
#include <string>
using namespace std;

string s;
int a, b, n;

bool canBe00()
{
     return b - a + n + 2 >> 1 <= n;
}

bool canBe01()
{
     if (a - b + n + 1 < 0) return false;
     int cnt = a - b + n + 1 >> 1;
     if (cnt > n) return false;
     string tmp = s;
     for (int i = tmp.length() - 1; i >= 0; i--)
         if (tmp[i] == '?')
            if (cnt) {
                     tmp[i] = '1'; cnt--;
            } else tmp[i] = '0';
     return tmp[tmp.length() - 1] == '1';
}

bool canBe10()
{
     if (a - b + n + 1 < 0) return false;
     int cnt = a - b + n + 1 >> 1;
     if (cnt > n) return false;
     string tmp = s;
     for (int i = 0; i < tmp.length(); i++)
         if (tmp[i] == '?')
            if (cnt) {
                     tmp[i] = '1'; cnt--;
            } else tmp[i] = '0';
     return tmp[tmp.length() - 1] == '0';
}

bool canBe11()
{
     return a - b + n + 3 >> 1 <= n;
}

int main()
{
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '0') a++;
        else if (s[i] == '1') b++;
        else n++;
    if (canBe00()) cout << "00\n";
    if (canBe01()) cout << "01\n";
    if (canBe10()) cout << "10\n";
    if (canBe11()) cout << "11\n";
    return 0;
}