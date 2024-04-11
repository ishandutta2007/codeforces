#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int N = 160;
int c[N][N];
int b[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    int q;
    scanf("%d", &q);

    for (int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            b[i][j]=c[i][j]=0;

    c[N/2-1][N/2-1] = n;
    int lox=N/2-1;
    int loy=N/2-1;
    int hix=N/2-1;
    int hiy=N/2-1;

    while(1)
    {
        bool any=false;
        bool tany=false;
        for (int i=lox; i<=hix;i++)
            for (int j=loy;j<=hiy;j++)
            {
                if(c[i][j]>=4)
                    any=true;
                if(c[i][j]>=4&&i==lox)
                    tany=true;
                b[i][j] = c[i][j] - (c[i][j] >= 4 ? 4 : 0);
            }
        if(!any)
            break;
        for (int i=lox;i<=hix;i++)
            for (int j=loy;j<=hiy;j++)
                if (c[i][j] >= 4)
                {
                    b[i-1][j]++;
                    b[i][j-1]++;
                    b[i+1][j]++;
                    b[i][j+1]++;
                }
        if(tany)
        {
            lox--;
            hix++;
            loy--;
            hiy++;
            if(hiy>N/2)
                hiy=N/2;
            if(hix>N/2)
                hix=N/2;
        }
        for(int i=lox;i<=N/2-1;i++)
            b[i][N/2]=b[i][N/2-2];
        for(int j=loy;j<=N/2-1;j++)
            b[N/2][j]=b[N/2-2][j];
        b[N/2][N/2]=b[N/2-2][N/2-2];
        for(int i=lox;i<=hix;i++)
            for(int j=loy;j<=hiy;j++)
                c[i][j]=b[i][j];
    }

    for (int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        if(x>0)
            x=-x;
        if(y>0)
            y=-y;
        x += N/2-1;
        y += N/2-1;
        if(x<0||y<0)
        {
            puts("0");
        }
        else
        {
            printf("%d\n", c[x][y]);
        }
    }
    return 0;
}