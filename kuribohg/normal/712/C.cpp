#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,ans;
int x[3];
int main()
{
    scanf("%d%d",&a,&b);
    x[0]=x[1]=x[2]=b;
    while(true)
    {
        sort(x,x+3);
        x[0]=x[1]+x[2]-1;
        ans++;
        if(x[0]>=a) break;
    }
    cout<<ans+2<<endl;
    return 0;
}