#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
bool ok;
char str[1010][10];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",str[i]);
    for(int i=1;i<=n;i++)
    {
        if(str[i][0]=='O'&&str[i][1]=='O') {str[i][0]=str[i][1]='+';ok=true;break;}
        if(str[i][3]=='O'&&str[i][4]=='O') {str[i][3]=str[i][4]='+';ok=true;break;}
    }
    if(ok)
    {
        puts("YES");
        for(int i=1;i<=n;i++) puts(str[i]);
    }
    else puts("NO");
    return 0;
}