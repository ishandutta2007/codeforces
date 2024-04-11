# include <iostream>
# include <cstdio>
using namespace std;
const int N=100010;

int a[N],b[N],c,t=0,s=0;
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d%d",a+i,b+i);
    s=a[0]*b[0];
    while(m--){
        scanf("%d",&c);
        while(s<c){++t;s+=a[t]*b[t];}
        printf("%d\n",t+1);
    }
    return 0;
}