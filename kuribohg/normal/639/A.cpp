#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int n,q,k,a[MAXN],b[100];
bool p[MAXN];
int main()
{
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    while(q--)
    {
        int op,x;
        scanf("%d%d",&op,&x);
        if(op==1)
        {
            p[x]=true;
            int o=a[x];
            for(int i=0;i<6;i++)
                if(o>b[i])
                {
                    for(int j=6;j>i;j--)
                        b[j]=b[j-1];
                    b[i]=o;
                    break;
                }
        }
        else
        {
            if(!p[x]) puts("NO");
            else if(a[x]<b[k-1]) puts("NO");
            else puts("YES");
        }
    }
    return 0;
}