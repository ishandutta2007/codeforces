#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
char s[maxn];
int n;
int main()
{
    int T,i,cnt;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s),n=strlen(s);
        for(i=0;i<n;i++)
            if(s[i]=='0')
                break;
        if(i>=n) { printf("0\n"); continue; }
        for(cnt=0,i=0;i<n;i++)
            if(s[i]=='0' && (!i || s[i-1]=='1'))
                cnt++;
        if(cnt==1) printf("1\n");
        else printf("2\n");
    }
    return 0;
}