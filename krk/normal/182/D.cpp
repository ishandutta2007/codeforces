#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string a, b;
int divs;

bool Divs(int l, const string &s)
{
    for (int i = 0; i < s.length(); i++)
        if (a[i % l] != s[i]) return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> a >> b;
    for (int i = 1; i <= a.length() && i <= b.length(); i++)
        if (a.length() % i == 0 && b.length() % i == 0 &&
            Divs(i, a) && Divs(i, b)) divs++;
    cout << divs << endl;
    return 0;
}