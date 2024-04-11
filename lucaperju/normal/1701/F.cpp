#include <bits/stdc++.h>

using namespace std;
const long long bucket_size=451,pzmax=200000;
long long whatbucket (long long pz)
{
    return pz/bucket_size+1;
}
long long ocp[200005],nrmid[200005],d;
long long ans=0;
long long nrInB[500];
struct ura
{
    long long cnt,val;
}lft[500],rght[500];
void calc (long long nrb)
{
    long long l=(nrb-1)*bucket_size,r=l+bucket_size-1;
    if(l==0)
        l=1;
    long long sc=lft[nrb].val,inc=lft[nrb].cnt;
    lft[nrb]={0,0};
    for(long long i=l;i<=r;++i)
    {
        nrmid[i]+=sc;
        if(ocp[i])
            sc+=inc;
    }
    sc=rght[nrb].val,inc=rght[nrb].cnt;
    rght[nrb]={0,0};
    for(long long i=r;i>=l;--i)
    {
        nrmid[i]+=sc;
        if(ocp[i])
            sc+=inc;
    }
}
void add (long long pz)
{
    ocp[pz]=1;
    ans+=nrmid[pz];
    long long nrb=whatbucket(pz),l=(nrb-1)*bucket_size,r=l+bucket_size-1;
    ++nrInB[nrb];
    long long lst=min(pz+d,pzmax);
    long long cntc=0,i;
    long long lstb=whatbucket(lst);
    for(i=pz+1;i<=min(r,lst);++i)
        if(ocp[i])
            ans+=cntc,++cntc;
    for(i=nrb+1;i<lstb;++i)
    {
        long long cur=nrInB[i];
        ans+=cntc*1LL*cur + cur*1LL*(cur-1LL)/2LL;
        cntc+=cur;
    }
    if(lstb!=nrb)
        for(i=(lstb-1)*bucket_size;i<=lst;++i)
            if(ocp[i])
                ans+=cntc,++cntc;
    cntc=0;
    if(lstb!=nrb)
        for(i=lst;i>=(lstb-1)*bucket_size;--i)
        {
            nrmid[i]+=cntc;
            if(ocp[i])
                ++cntc;
        }
    for(i=lstb-1;i>nrb;--i)
    {
        long long cur=nrInB[i];
        rght[i].cnt++;
        rght[i].val+=cntc;
        cntc+=cur;
    }
    for(i=min(r,lst);i>pz;--i)
    {
        nrmid[i]+=cntc;
        if(ocp[i])
            ++cntc;
    }
    ///---------
    cntc=0;
    lst=max(1LL,pz-d);
    lstb=whatbucket(lst);
    for(i=pz-1;i>=max(l,lst);--i)
        if(ocp[i])
            ans+=cntc,++cntc;
    for(i=nrb-1;i>lstb;--i)
    {
        long long cur=nrInB[i];
        ans+=cntc*1LL*cur + cur*1LL*(cur-1LL)/2LL;
        cntc+=cur;
    }
    if(lstb!=nrb)
        for(i=lstb*bucket_size-1;i>=lst;--i)
            if(ocp[i])
                ans+=cntc,++cntc;
    cntc=0;
    if(lstb!=nrb)
        for(i=lst;i<=lstb*bucket_size-1;++i)
        {
            nrmid[i]+=cntc;
            if(ocp[i])
                ++cntc;
        }
    for(i=lstb+1;i<nrb;++i)
    {
        long long cur=nrInB[i];
        lft[i].cnt++;
        lft[i].val+=cntc;
        cntc+=cur;
    }
    for(i=max(l,lst);i<pz;++i)
    {
        nrmid[i]+=cntc;
        if(ocp[i])
            ++cntc;
    }
}
void rem (long long pz)
{
    ocp[pz]=0;
    ans-=nrmid[pz];
    long long nrb=whatbucket(pz),l=(nrb-1)*bucket_size,r=l+bucket_size-1;
    --nrInB[nrb];
    long long lst=min(pz+d,pzmax);
    long long cntc=0,i;
    long long lstb=whatbucket(lst);
    for(i=pz+1;i<=min(r,lst);++i)
        if(ocp[i])
            ans-=cntc,++cntc;
    for(i=nrb+1;i<lstb;++i)
    {
        long long cur=nrInB[i];
        ans-=cntc*1LL*cur + cur*1LL*(cur-1LL)/2LL;
        cntc+=cur;
    }
    if(lstb!=nrb)
        for(i=(lstb-1)*bucket_size;i<=lst;++i)
            if(ocp[i])
                ans-=cntc,++cntc;
    cntc=0;
    if(lstb!=nrb)
        for(i=lst;i>=(lstb-1)*bucket_size;--i)
        {
            nrmid[i]-=cntc;
            if(ocp[i])
                ++cntc;
        }
    for(i=lstb-1;i>nrb;--i)
    {
        long long cur=nrInB[i];
        rght[i].cnt--;
        rght[i].val-=cntc;
        cntc+=cur;
    }
    for(i=min(r,lst);i>pz;--i)
    {
        nrmid[i]-=cntc;
        if(ocp[i])
            ++cntc;
    }
    ///---------
    cntc=0;
    lst=max(1LL,pz-d);
    lstb=whatbucket(lst);
    for(i=pz-1;i>=max(l,lst);--i)
        if(ocp[i])
            ans-=cntc,++cntc;
    for(i=nrb-1;i>lstb;--i)
    {
        long long cur=nrInB[i];
        ans-=cntc*1LL*cur + cur*1LL*(cur-1LL)/2LL;
        cntc+=cur;
    }
    if(lstb!=nrb)
        for(i=lstb*bucket_size-1;i>=lst;--i)
            if(ocp[i])
                ans-=cntc,++cntc;
    cntc=0;
    if(lstb!=nrb)
        for(i=lst;i<=lstb*bucket_size-1;++i)
        {
            nrmid[i]-=cntc;
            if(ocp[i])
                ++cntc;
        }
    for(i=lstb+1;i<nrb;++i)
    {
        long long cur=nrInB[i];
        lft[i].cnt--;
        lft[i].val-=cntc;
        cntc+=cur;
    }
    for(i=max(l,lst);i<pz;++i)
    {
        nrmid[i]-=cntc;
        if(ocp[i])
            ++cntc;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,i,j;
    cin>>n>>d;
    for(i=1;i<=n;++i)
    {
        long long a;
        cin>>a;
        calc(whatbucket(a));
        if(!ocp[a])
            add(a);
        else
            rem(a);
        cout<<ans<<'\n';
    }
}