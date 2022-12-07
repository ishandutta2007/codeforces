#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int ans;
char str[10];
int main()
{
    scanf("%s",str);
    if(str[0]=='a'||str[0]=='h') ans++;
    if(str[1]=='1'||str[1]=='8') ans++;
    if(ans==0) puts("8");
    else if(ans==1) puts("5");
    else puts("3");
    return 0;
}