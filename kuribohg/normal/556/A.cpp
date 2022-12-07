#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char str[300010];
int main()
{
    scanf("%d",&n);
    scanf("%s",str);
    int len=strlen(str);
    int cnt1=0,cnt2=0;
    for(int i=0;i<len;i++)
        if(str[i]=='0') cnt1++;
        else cnt2++;
    printf("%d\n",len-min(cnt1,cnt2)*2);
    return 0;
}