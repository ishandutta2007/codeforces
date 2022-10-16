#include <algorithm>
#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

bool abseq(char* a, int l, char* b)
{
    for (int i = 0; i < l; ++i)
        if (a[i] != b[i])
            return 0;
    return 1;
}

void mini(char* a, int l)
{
    if ((l & 1) == 1)
        return;
    mini(a, l / 2);
    mini(a + l / 2, l / 2);
    bool f = 0;
    for (int i = 0; i < l / 2; ++i)
        if (a[i] > a[i + l / 2])
        {
            f = 1;
            break;
        }
        else if (a[i] < a[i + l / 2])
            break;
    if (f)
        for (int i = 0; i < l / 2; ++i)
            swap(a[i], a[i + l / 2]);
}

bool eq(char* a, int l, char* b)
{
    bool f = 0;
    for (int i = 0; i < l; ++i)
        if (a[i] != b[i])
        {
            f = 1;
            break;
        }
    if (!f)
        return 1;
    if (l == 1)
        return 0;
    return (eq(a, l / 2, b) && eq(a + l / 2, l / 2, b + l / 2)) ||
           (eq(a + l / 2, l / 2, b) && eq(a, l / 2, b + l / 2));
}
char a[200001], b[200001];

int main()
{
    int l = 0;
    while (cin.peek() != '\n')
        a[l++] = cin.get();
    for (int i = 0; i < l; ++i)
        cin >> b[i];
    mini(a, l);
    mini(b, l);
    cout << (abseq(a, l, b)? "YES":"NO");
}