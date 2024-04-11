#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char opt[4];
    int x,y;
    int maxx=0,maxy=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%s%d%d",opt,&x,&y);
        if(opt[0]=='+')
        {
            if(x>y)
            {
                swap(x,y);
            }
            maxx=max(maxx,x);
            maxy=max(maxy,y);
        }
        else
        {
            if(x>y)
            {
                swap(x,y);
            }
            if(x>=maxx&&y>=maxy)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
}