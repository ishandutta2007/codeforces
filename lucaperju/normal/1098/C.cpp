#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;
long long n,s,cur[100005],cur1[100005];
long long verif (long long x)
{
    long long sc=1,pr=1,pz=1,p=x;
    cur[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(i-pz<=p)
            cur[i]=pr+1,sc+=cur[i];
        else
        {
            ++pr;
            p=p*1LL*x;
            pz=i-1;
            cur[i]=pr+1;
            sc+=cur[i];
        }
    }
    return sc;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie();
    long long ci,cc,i,j,cnt0,a,b,k=1,ok=0,m,mn=30000003,cnt1,cnt=1,t,w,h,u1,h1,u2,h2,sc;
    cin>>n>>s;
    if(s>n*1LL*(n+1)/2LL || s<1LL+(n-1)*2LL)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    long long pas=1LL<<20;
    while(pas)
    {
        if(k+pas<n && verif(k+pas)>s)
            k+=pas;
        pas>>=1LL;
    }
    sc=verif(k);
    if(sc>s)
        ++k;
    sc=s-verif(k);
    for(i=1;i<=n;++i)
        ++cur1[cur[i]];
    for(i=n;i>=1;--i)
    {
        while(cur1[i]>1 && sc>=cnt)
        {
            sc-=cnt;
            --cur1[i];
            ++cur1[i+cnt];
            ++cnt;
        }
        if(cur1[i]==1)
            ++cnt;
        if(cur1[i]>1)
        {
            --cur1[i];
            ++cur1[i+sc];
            break;
        }
    }
    long long cntc=1,pz=1;
    for(i=2;i<=n;++i)
    {
        long long curc=1,ccnt=cntc;
        while(cur1[i])
        {
            if(curc>k)
                ++pz,curc-=k;
            cout<<pz<<' ';
            ++cntc;
            ++curc;
            --cur1[i];
        }
        pz=ccnt+1;
    }
}