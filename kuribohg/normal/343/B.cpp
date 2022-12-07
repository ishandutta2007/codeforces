#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int len,top;
char str[1000010],S[1000010];
int main()
{
    scanf("%s",str);
    len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(top!=0&&S[top]==str[i]) top--;
        else S[++top]=str[i];
    }
    if(top==0) puts("Yes");
    else puts("No");
    return 0;
}