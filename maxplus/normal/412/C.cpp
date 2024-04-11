#include <iostream>
#include <cstdlib>
#include <cstdio>

//#include <algorithm>
//#include <cstring>
//#include <string>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <cmath>


using namespace std;

char a[100002];

int main()
{
    int n, l, tl;
    char c;
    cin >> n;
    scanf("%c", &c);
    for (int i = 0; i < n; ++i)
    {
        tl = 0;
        while (1)
        {
            scanf("%c", &c);
            tl++;
            if (c != '?')
            {
                if (c == '\n')
                {
                    l = tl - 1;
                    break;
                }
                if (a[tl] == 0)
                    a[tl] = c;
                if (a[tl] != c)
                    a[tl] = '?';
            }
        }
    }
    for (int i = 1; i <= l; ++i)
        if (a[i] == 0)
            cout << 'o';
        else
            cout << a[i];
    return 0;
}