#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long ans_a[65],ans_b[65];
long long c[65][65];
const int modo = 998244353;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i;
    for (i=0;i<=60;i++)
    {
        int j;
        c[i][0] = 1;
        for (j=1;j<=i;j++)
        {
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
    for (i=2;i<=60;i+=2)
    {
        ans_a[i] = c[i-1][i/2] + ans_b[i-2];
        ans_b[i] = c[i-2][i/2] + ans_a[i-2];
    }
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int n;
        scanf("%d",&n);
        printf("%d %d 1\n",(int)(ans_a[n]%modo),(int)(ans_b[n]%modo));
    }
    return 0;
}