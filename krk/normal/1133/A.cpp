#include <bits/stdc++.h>
using namespace std;

int Read()
{
    string s; cin >> s;
    return (int(s[0] - '0') * 10 + int(s[1] - '0')) * 60 + int(s[3] - '0') * 10 + int(s[4] - '0');
}

int main()
{
    int a = Read(), b = Read();
    int c = a + b >> 1;
    int h = c / 60, m = c % 60;
    printf("%d%d:%d%d\n", h / 10, h % 10, m / 10, m % 10);
    return 0;
}