#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,now;
char str[1010];
int main()
{
    scanf("%s",str);
    n=strlen(str);
    for(int i=0;i<n;i++)
        if(str[i]<now+'a') continue;
        else if(str[i]==now+'a') {now++;continue;}
        else {puts("NO");return 0;}
    puts("YES");
    return 0;
}