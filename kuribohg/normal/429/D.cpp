#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=1000010;
typedef long long LL;
int n,tot;
LL a[MAXN],s[MAXN];
pair<LL,LL> P[MAXN],Q[MAXN];
bool cmp(const pair<LL,LL> &p,const pair<LL,LL> &q)
{
    return p.second<q.second;
}
LL Dis(const pair<LL,LL> &p,const pair<LL,LL> &q)
{
    return (p.first-q.first)*(p.first-q.first)+(p.second-q.second)*(p.second-q.second);
}
LL Solve(int l,int r)
{
    LL ans=8000000000000000000LL;
    if(r-l+1<=3)
    {
        for(int i=l;i<=r;i++)
            for(int j=i+1;j<=r;j++)
                ans=min(ans,Dis(P[i],P[j]));
        return ans;
    }
    int mid=(l+r)>>1;
    ans=min(ans,Solve(l,mid));
    ans=min(ans,Solve(mid+1,r));
    tot=0;
    for(int i=l;i<=r;i++)
        if((P[mid].first-P[i].first)*(P[mid].first-P[i].first)<=ans) Q[++tot]=P[i];
    sort(Q+1,Q+tot+1,cmp);
    LL limit=ans;
    for(int i=1;i<=tot;i++)
        for(int j=i+1;j<=tot;j++)
        {
            if((Q[j].second-Q[i].second)*(Q[j].second-Q[i].second)>limit) break;
            ans=min(ans,Dis(Q[i],Q[j]));
        }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++) P[i].first=i,P[i].second=s[i];
    sort(P+1,P+n+1);
    LL ans=Solve(1,n);
    cout<<ans<<endl;
    return 0;
}