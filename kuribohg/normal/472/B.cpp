#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
int n,k,a[100010],sub=1,ans;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,greater<int>());
    while(sub<=n) ans+=a[sub]-1,sub+=k;
    ans<<=1;
    printf("%d\n",ans);
    return 0;
}