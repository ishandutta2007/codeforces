#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;
bool found;

void Print(int num)
{
    printf("YES\n");
    printf("%d\n", num);
}

void Gen(int lvl, int from, int has)
{
    if (lvl && has % 8 == 0) { Print(has); found = true; }
    if (lvl < 3)
        for (int i = from; i < s.length() && !found; i++)
            Gen(lvl + 1, i + 1, has * 10 + s[i] - '0');
}

int main()
{
    cin >> s;
    Gen(0, 0, 0);
    if (!found) printf("NO\n");
    return 0;
}