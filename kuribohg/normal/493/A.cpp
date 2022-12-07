#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
char a[31],b[31],op[20],c[20];
int t1[1010],t2[1010],T,n,num;
int main()
{
    scanf("%s%s%d",a,b,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%s%d%s",&T,op,&num,c);
        if(op[0]=='h')
        {
            if(c[0]=='r'&&t1[num]<2) printf("%s %d %d\n",a,num,T),t1[num]=10;
            else if(c[0]=='y'&&t1[num]<2)
            {
                t1[num]++;
                if(t1[num]==2) printf("%s %d %d\n",a,num,T);
            }
        }
        else
        {
            if(c[0]=='r'&&t2[num]<2) printf("%s %d %d\n",b,num,T),t2[num]=10;
            else if(c[0]=='y'&&t2[num]<2)
            {
                t2[num]++;
                if(t2[num]==2) printf("%s %d %d\n",b,num,T);
            }
        }
    }
    return 0;
}