#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char str[30];
int main()
{
    scanf("%s",str);
    int n=strlen(str);
    printf("%d\n",(n+1)*26-n);
    return 0;
}