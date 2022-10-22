#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int f, s;

int main()
{
    getline(cin, a); getline(cin, b);
    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i])
           if (a[i] == '4') f++;
           else s++;
    int mn = min(f, s);
    cout << mn + f - mn + s - mn << endl;
    return 0;
}