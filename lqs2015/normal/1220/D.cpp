#include<bits/stdc++.h>
using namespace std;
int n;
long long a[222222],cur;
vector<long long> v,ans;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    cur=1;
    for (int i=1;i<=n;i++) ans.push_back(a[i]);
    for (int i=1;i<=60;i++)
    {
        v.clear();
        for (int j=1;j<=n;j++)
        {
            if ((a[j]%cur) || (a[j]/cur)%2==0) v.push_back(a[j]);
        }
        if ((int)v.size()<(int)ans.size()) ans=v;
        cur<<=1;
    }
    printf("%d\n",(int)ans.size());
    for (int i=0;i<ans.size();i++) printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}