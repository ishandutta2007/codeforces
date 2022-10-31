#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 200000
int n,m,cnt;
char a[MAXN+10],c[30];
int main()
{
    int i;
    char x[2],y[2];
    scanf("%d%d%s",&n,&m,a);
    for(i=0;i<26;i++)
        c[i]=i+'a';
    while(m--){
        scanf("%s%s",x,y);
        for(i=0;i<26;i++)
            if(c[i]==x[0])
                c[i]=y[0];
            else if(c[i]==y[0])
                c[i]=x[0];
    }
    for(i=0;i<n;i++)
        putchar(c[a[i]-'a']);
}