#include <bits/stdc++.h>
using namespace std;
#define N 100005
int T,a,b,p,n;bool fl;char s[N];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %s",&a,&b,&p,s);n=strlen(s);s[n-1]='C';fl=1;
        for(int i=n-1;i>=1 && fl;--i)
        	if(s[i-1]!=s[i] && s[i-1]=='A' && (p-=a)<0) {printf("%d\n",i+1);fl=0;break;}
            else if(s[i-1]!=s[i] && s[i-1]=='B' && (p-=b)<0) {printf("%d\n",i+1);fl=0;break;}
        if(fl) puts("1");
    }return 0;
}