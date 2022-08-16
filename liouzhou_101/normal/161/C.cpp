#include<iostream>
#include<algorithm>

using namespace std;

int L[2],R[2];
int full[2][40],L_full[2][40],R_full[2][40],L_have[2][40],R_have[2][40];

void solve(int p,int k,int L,int R)
{
    if (full[p][k]) return;
    int tmp=(1<<k)-1;
    int mid=(1+tmp)>>1;
    if (R<mid)
        solve(p,k-1,L,R);
    else if (L>mid)
        solve(p,k-1,L-mid,R-mid);
    else
    {
        L_have[p][k]=max(L_have[p][k],mid-L+1);
        R_have[p][k]=max(R_have[p][k],R-mid+1);
        if (mid-L==tmp>>1)
        {
            if (!L_full[p][k])
                for (int i=1;i<k;++i)
                    full[p][i]=1;
            L_full[p][k]=max(L_full[p][k],R-mid+1);
        }
        if (R-mid==tmp>>1)
        {
            if (!R_full[p][k])
                for (int i=1;i<k;++i)
                    full[p][i]=1;
            R_full[p][k]=max(R_full[p][k],mid-L+1);
        }
        if (L<=mid-1)
            solve(p,k-1,L,mid-1);
        if (mid+1<=R)
            solve(p,k-1,1,R-mid);
    }
}

int main()
{
    for (int p=0;p<2;++p)
    {
        cin>>L[p]>>R[p];
        solve(p,30,L[p],R[p]);
    }
    int ans=0;
    for (int i=1;i<=30;++i)
    {
        if (full[0][i]&&full[1][i])
        {
            ans=max(ans,(1<<i)-1);
            continue;
        }
        if (full[0][i])
        {
            if (L_full[1][i])
                ans=max(ans,(1<<(i-1))+L_full[1][i]-1);
            if (R_full[1][i])
                ans=max(ans,(1<<(i-1))+R_full[1][i]-1);
            if (!L_full[1][i]&&!R_full[1][i])
                ans=max(ans,L_have[1][i]+R_have[1][i]-1);
            continue;
        }
        if (full[1][i])
        {
            if (L_full[0][i])
                ans=max(ans,(1<<(i-1))+L_full[0][i]-1);
            if (R_full[0][i])
                ans=max(ans,(1<<(i-1))+R_full[0][i]-1);
            if (!L_full[0][i]&&!R_full[0][i])
                ans=max(ans,L_have[0][i]+R_have[0][i]-1);
            continue;
        }
        if (L_full[0][i])
        {
            if (L_full[1][i])
                ans=max(ans,(1<<(i-1))+min(L_full[0][i],L_full[1][i])-1);
            if (R_full[1][i])
                ans=max(ans,L_full[0][i]+R_full[1][i]-1);
            if (!L_full[1][i]&&!R_full[1][i])
                ans=max(ans,L_have[1][i]+min(L_full[0][i],R_have[1][i])-1);
        }
        if (R_full[0][i])
        {
            if (L_full[1][i])
                ans=max(ans,L_full[1][i]+R_full[0][i]-1);
            if (R_full[1][i])
                ans=max(ans,(1<<(i-1))+min(R_full[0][i],R_full[1][i])-1);
            if (!L_full[1][i]&&!R_full[1][i])
                ans=max(ans,R_have[1][i]+min(R_full[0][i],L_have[1][i])-1);
        }
        if (L_full[1][i])
        {
            if (L_full[0][i])
                ans=max(ans,(1<<(i-1))+min(L_full[1][i],L_full[0][i])-1);
            if (R_full[0][i])
                ans=max(ans,L_full[1][i]+R_full[0][i]-1);
            if (!L_full[0][i]&&!R_full[0][i])
                ans=max(ans,L_have[0][i]+min(L_full[1][i],R_have[0][i])-1);
        }
        if (R_full[1][i])
        {
            if (L_full[0][i])
                ans=max(ans,L_full[0][i]+R_full[1][i]-1);
            if (R_full[0][i])
                ans=max(ans,(1<<(i-1))+min(R_full[1][i],R_full[0][i])-1);
            if (!L_full[0][i]&&!R_full[0][i])
                ans=max(ans,R_have[0][i]+min(R_full[1][i],L_have[0][i])-1);
        }
        if (!L_full[0][i]&&!L_full[1][i]&&!R_full[0][i]&&!R_full[1][i])
        if (L_have[0][i]&&L_have[1][i]&&R_have[0][i]&&R_have[1][i])
            ans=max(ans,min(L_have[0][i],L_have[1][i])+min(R_have[0][i],R_have[1][i])-1);
    }
    cout<<ans<<endl;
    return 0;
}