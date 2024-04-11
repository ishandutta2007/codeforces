#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int u,d,l,r;
char str[MAXN];
int main()
{
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
        if(str[i]=='U') u++;
        else if(str[i]=='D') d++;
        else if(str[i]=='L') l++;
        else if(str[i]=='R') r++;
    if(len&1) {puts("-1");return 0;}
    int ans=(max(u,d)-min(u,d))/2+(max(l,r)-min(l,r))/2+((l+r)&1);
    cout<<ans<<endl;
    return 0;
}