#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
char s[maxn];
int n;
int main()
{
    int i,tot=0;
    scanf("%d%s",&n,s);
    for(i=0;i<n;i++)
    {
        if(s[i]=='(') tot++;
        else tot--;
        if(tot<-1)
        {
            printf("No\n");
            return 0;
        }
    }
    if(tot) printf("No\n");
    else printf("Yes");
    return 0;
}