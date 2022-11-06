#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
int X, Y;
int main() 
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        map<int, int> xx, yy;
        int qx, qy;
        for(int i = 1; i <= 3; i ++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            xx[x] ++;
            yy[y] ++;
            if(xx[x] == 2) qx = x;
            if(yy[y] == 2) qy = y;
        }
        scanf("%d%d", &X, &Y);

        if((qy == 1 || qy == n) && (qx == 1 || qx == n)) 
        {
            if(qx == X || qy == Y) puts("Yes");
            else puts("No");
        } 
        else 
        {
            if(abs(qy - Y) % 2 == 0 || abs(qx - X) % 2 == 0) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}