#include<bits/stdc++.h>
using namespace std;
int l,r,u,d;
int n;
char s[200000];
int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L') l++;
        if(s[i]=='R') r++;
        if(s[i]=='U') u++;
        if(s[i]=='D') d++;
    }
    printf("%d",2*min(l,r)+2*min(u,d));
    return 0;
}