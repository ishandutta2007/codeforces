#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

string s;
int best = -1;

bool canGet(const string &s, int &num)
{
    if (s[0] == '0' && s.length() > 1) return false;
    if (s.length() > 7) return false;
    stringstream ss(s);
    ss >> num;
    return num <= 1000000;
}

int main()
{
    cin >> s;
    for (int i = 1; i < s.length(); i++)
        for (int j = i + 1; j < s.length(); j++) {
            int num1, num2, num3;
            if (canGet(s.substr(0, i), num1) && canGet(s.substr(i, j - i), num2) &&
                canGet(s.substr(j), num3)) best = max(best, num1 + num2 + num3);
        }
    cout << best << endl;
    return 0;
}