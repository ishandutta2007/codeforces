#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int n;
LL A,B,C;
char str[100010];
bool used[100010];
int main()
{
    scanf("%s",str);
    n=strlen(str);
    for(int i=0;i<n-1;i++)
        if(str[i]=='A'&&str[i+1]=='B') A++;
    for(int i=0;i<n-1;i++)
        if(str[i]=='B'&&str[i+1]=='A') B++;
    for(int i=0;i<n-2;i++)
        if(str[i]=='A'&&str[i+1]=='B'&&str[i+2]=='A') C++;
    for(int i=0;i<n-2;i++)
        if(str[i]=='B'&&str[i+1]=='A'&&str[i+2]=='B') C++;
    if(A*B-C) puts("YES");
    else puts("NO");
    return 0;
}