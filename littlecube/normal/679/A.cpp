#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string s;
    int r = 0;
    int p[19] = {2, 3, 4, 5, 7, 9, 11, 13, 17, 19, 23, 25, 29, 31, 37, 41, 43, 47, 49};
    for (int i = 0; i < 19; i++)
    {
        cout << p[i] << endl;
        cin >> s;
        if (s == "yes")
            r++;
    }
    if (r >= 2)
        cout << "composite" << endl;
    else
        cout << "prime" << endl;
    return 0;
}