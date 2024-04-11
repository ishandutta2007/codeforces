#include <cstdio>
#include <cstring>
const int maxn=105;
char str[maxn],s[2],t[2];
int main()
{
    int i,q;
    scanf("%*d%d%s",&q,str+1);
    while(q--)
    {
        int l,r;
        scanf("%d%d%s%s",&l,&r,s,t);
        for(i=l;i<=r;i++)
            if(str[i]==s[0])
                str[i]=t[0];
    }
    printf("%s\n",str+1);
    return 0;
}