#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[200];
int w,n,ans;
int main()
{
    scanf("%s%d",s,&w);
    n=strlen(s);
    for(int i=n-1;i>=0;i--)
        if(s[i]!='0'&&w>0) ans++;
        else w--;
    if(w>0) printf("%d\n",n-1);
    else printf("%d\n",ans);
    return 0;
}