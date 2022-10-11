#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
    string s = "";
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n / 2; i++)
        s += ((i % 2 == 1) ? "aa" : "bb");
    if (n % 2 == 1)
        s += ((s[n - 2] == 'a') ? 'b' : 'a');
    printf("%s", s.c_str());
}