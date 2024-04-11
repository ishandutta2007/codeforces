#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,used[1010],len,x;
int main()
{
    scanf("%d",&n);
    scanf("%d",&len);
    for(int i=1;i<=len;i++) scanf("%d",&x),used[x]=true;
    scanf("%d",&len);
    for(int i=1;i<=len;i++) scanf("%d",&x),used[x]=true;
    for(int i=1;i<=n;i++)
        if(!used[i]) {puts("Oh, my keyboard!");return 0;}
    puts("I become the guy.");
    return 0;
}