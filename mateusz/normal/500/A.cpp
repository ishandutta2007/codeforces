#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 100005;
int a[N];
int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    for(int i = 1; i < n; i++)
        scanf("%d", &a[i]);
    int where = 1;
    int canGet = false;
    while(where < n)
    {
        if(where == t)
        {
            canGet = true;
            break;
        }
        where = where + a[where];
    }
    printf(canGet == true || t == n? "YES": "NO");
    return 0;
}