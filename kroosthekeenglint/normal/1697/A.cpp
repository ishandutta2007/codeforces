#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<memory>
#include<time.h>
#include<math.h>
#include<bitset>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<utility>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
    int n,m;
    int t;
    scanf("%d",&t);
    int i;
    for (i=0;i<t;i++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int i;
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            m-=x;
        }
        m=max(-m,0);
        printf("%d\n",m);
    } 
    return 0;
}