#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char a[1000],b[1000],str[10000];
int d,tot;
char ans[2010];
void work(char str[])
{
    int cur=0;
    while(str[cur]!='.') a[cur]=str[cur],cur++;
    cur++;
    int sub=0;
    while(str[cur]!='e') b[sub]=str[cur],cur++,sub++;
    int len=strlen(str);
    for(int i=cur+1;i<len;i++)
        d=d*10+str[i]-'0';
}
int main()
{
    scanf("%s",str);
    work(str);
    for(int i=0;i<strlen(a);i++)
        ans[tot++]=a[i];
    if(d<strlen(b))
    {
        for(int i=0;i<d;i++) ans[tot++]=b[i];
        ans[tot++]='.';
        for(int i=d;i<strlen(b);i++) ans[tot++]=b[i];
    }
    else
    {
        for(int i=0;i<strlen(b);i++) ans[tot++]=b[i];
        for(int i=strlen(b);i<d;i++) ans[tot++]='0';
    }
    int cur=0,tail=strlen(ans)-1;
    while(ans[cur]=='0') cur++;
    bool ok=false;
    for(int i=0;i<=tail;i++) if(ans[i]=='.') ok=true;
    if(ok)
    {
        while(ans[tail]=='0') tail--;
        if(ans[tail]=='.') tail--;
    }
    if(ans[cur]=='.') putchar('0');
    for(int i=cur;i<=tail;i++)
        putchar(ans[i]);
    puts("");
    return 0;
}