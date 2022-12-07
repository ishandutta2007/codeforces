#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans,s;
char str[1000010],pre;
char op(char x)
{
    if(x=='0') return '1';
    else return '0';
}
int main()
{
    scanf("%d%s",&n,str);
    ans=1,pre=str[0];
    for(int i=1;i<n;i++)
    {
        if(str[i]!=pre)
        {
            ans++,pre=str[i];
            if(s==1) s=2;
        }
        else if(s<2) s=1,ans++,str[i]=op(str[i]),pre=str[i];
    }
    printf("%d\n",ans);
    return 0;
}