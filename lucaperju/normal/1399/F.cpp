#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int l,r;
};
struct ura1
{
    int l,r,cat;
};
vector<ura1>vc;
ura v[3003],vr[3003];
int dp[3003],dpc[3003],sumc[3003];
bool cmplength (ura a, ura b)
{
    int la=a.r-a.l;
    int lb=b.r-b.l;
    if(la<lb)
        return true;
    if(la>lb)
        return false;
    return a.r<b.r;
}
bool cmpright (ura a, ura b)
{
    return a.r<b.r;
}
int main()
{
    long long t,n,s,m,i,j,x,y,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>l>>r;
            v[i]={l,r};
            vr[i]={l,r};
        }
        sort(v+1,v+n+1,cmplength);
        sort(vr+1,vr+n+1,cmpright);
        v[n+1]={0,200005};
        int dpfc;
        for(i=1;i<=n+1;++i)
        {
            int lc=v[i].l;
            int rc=v[i].r;
            vc.clear();
            for(j=1;j<=n;++j)
            {
                if(vr[j].l>=lc && vr[j].r<=rc && (vr[j].l!=lc || vr[j].r!=rc))
                    vc.push_back({vr[j].l,vr[j].r,dp[j]});
            }
            for(j=0;j<vc.size();++j)
            {
                dpc[j]=vc[j].cat+1;
                int k=j;
                int pas=1<<12;
                while(pas)
                {
                    if(k-pas>=0 && vc[k-pas].r>=vc[j].l)
                        k-=pas;
                    pas>>=1;
                }
                --k;
                if(k==-1)
                {
                    sumc[j]=max(sumc[j-1],dpc[j]);
                    continue;
                }
                dpc[j]+=sumc[k];
                sumc[j]=max(sumc[j-1],dpc[j]);
            }
            dpfc=sumc[vc.size()-1];
            for(j=1;j<=n;++j)
            {
                if(vr[j].l==lc && vr[j].r==rc)
                    dp[j]=dpfc;
            }
        }
        cout<<dpfc<<'\n';
    }
    return 0;
}