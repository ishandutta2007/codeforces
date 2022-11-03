#include<bits/stdc++.h>
using namespace std;
const int N=200005;
typedef long long ll;
int n;ll T;
ll a[N];int nxt[N],la[N];
int main()
{
    scanf("%d%I64d",&n,&T);
    ll sum=0,mn=2147483647;
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]),sum+=a[i],nxt[i]=i+1,la[i]=i-1,mn=min(mn,a[i]);
    ll ans=0,num=n;int st=1;
    while(T>=mn)
    {
        ans+=(T/sum)*num;T%=sum;
        if(T<mn) break;
        for(int i=st,flag=0;i!=n+1;i=nxt[i])
            if(T>=a[i]){
                T-=a[i];ans++;if(T<mn) break;
                if(!flag) st=i,flag=1;
            }
            else nxt[la[i]]=nxt[i],la[nxt[i]]=la[i],sum-=a[i],num--;
    }
    printf("%I64d",ans);
    return 0;
}