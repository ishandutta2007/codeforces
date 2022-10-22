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
#define size s12389012
int size[1005];
int fa[1005];
int findroot(int x)
{
    int root;
    for (root=x;fa[root]!=-1;root=fa[root]) ;
    int temp;
    for (;fa[x]!=-1;)
    {
        temp = fa[x];
        fa[x] = root;
        x = temp;
    }
    return root;
}
void u(int x,int y)
{
    x = findroot(x);
    y = findroot(y);
    fa[x] = y;
    size[y] += size[x];
}
struct node
{
    int a;
    int i;
    friend bool operator < (const node &a,const node &b)
    {
        return a.a>b.a;
    }
};
node a[1005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int n;
        scanf("%d",&n);
        int i;
        for (i=0;i<n;i++)
        {
            fa[i] = -1;
            size[i] = 1;
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i].a);
            a[i].i = i;
        }
        sort(a,a+n);
        for (i=0;i<n;i++)
        {
            int cnt = 0;
            int y = a[i].i;
            for (;fa[y] == -1;)
            {
                if (cnt >= a[i].a)
                {
                    break;
                }
                printf("? %d\n", y+1);
                fflush(stdout);
                int x;
                scanf("%d",&x);
                x--;
                if (size[findroot(x)] != 1)
                {
                    u(y, x);
                    break;
                }
                else
                {
                    u(x, y);
                }
                cnt++;
            }
        }
        printf("!");
        for (i=0;i<n;i++)
        {
            printf(" %d",findroot(i)+1);
        }
        printf("\n");
        fflush(stdout);
    }
    return 0;
}