#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int n, m;

string s1, s2 = "12", s3;

int main()
{
    cin >> s1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s3;
        bool fl = true;
        if (s3.size() < s1.size()) continue;
        for (int ii = 0; ii < s1.size(); ii++)
        {
            if (s1[ii] != s3[ii]) fl = false;
        }
        if (fl)
        {
            if (s2 == "12") s2 = s3;
            if (s2 > s3) s2 = s3;
        }
    }
    if (s2 == "12") cout << s1; else cout << s2;
    return 0;
}