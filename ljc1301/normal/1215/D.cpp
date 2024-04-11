#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,m,cnta,cntb,sa,sb;
char s[maxn];
int main()
{
    int i;
    scanf("%d%s",&n,s+1),m=n/2;
    sa=sb=0,cnta=cntb=0;
    for(i=1;i<=m;i++)
        if(s[i]=='?') cnta++;
        else sa+=s[i]-'0';
    for(i=m+1;i<=2*m;i++)
        if(s[i]=='?') cntb++;
        else sb+=s[i]-'0';
    sa+=cnta/2*9,sb+=cntb/2*9;
    printf("%s\n",(sa==sb)?"Bicarp":"Monocarp");
    return 0;
}