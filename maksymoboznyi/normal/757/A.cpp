#include <iostream>

using namespace std;
int a[10];
int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
            a[1]++;
        if (s[i] == 'u')
            a[2]++;
        if (s[i] == 'l')
            a[3]++;
        if (s[i] == 'b')
            a[4]++;
        if (s[i] == 'a')
            a[5]++;
        if (s[i] == 's')
            a[6]++;
        if (s[i] == 'r')
            a[7]++;
    }
    a[5] /= 2;
    a[2] /= 2;
    int mi = a[1];
    for (int i = 2; i <= 7; i++)
        mi = min(mi, a[i]);
    cout << mi;
    return 0;
}