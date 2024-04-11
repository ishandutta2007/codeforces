#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
int n;
pair<int,int> a[100010];
bool p=true;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].first,&a[i].second);
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
        if(a[i].second>a[i+1].second) p=false;
    if(p) puts("Poor Alex");
    else puts("Happy Alex");
    return 0;
}