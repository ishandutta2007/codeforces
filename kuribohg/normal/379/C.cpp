#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
const int MAXN=300010;
int n,cur=-1,ans[MAXN];
pair<int,int> a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i].first),a[i].second=i;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i].first>cur) cur=a[i].first;
        else a[i].first=cur+1,cur=a[i].first;
    }
    for(int i=1;i<=n;i++) ans[a[i].second]=a[i].first;
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}