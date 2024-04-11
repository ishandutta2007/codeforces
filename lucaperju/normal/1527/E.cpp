#include <bits/stdc++.h>
using namespace std;
int v[35003];
int nxtr[35003],nxtl[35003];
int lst[35003];
int dpv[35003],dp[35005];
int L=1,R=0,S=0;
void addr ()
{
    ++R;
    if(nxtl[R]>=L)
        S+=R-nxtl[R];
}
void addl ()
{
    --L;
    if(nxtr[L]<=R)
        S+=nxtr[L]-L;
}
void remr ()
{
    if(nxtl[R]>=L)
        S-=R-nxtl[R];
    --R;
}
void reml ()
{
    if(nxtr[L]<=R)
        S-=nxtr[L]-L;
    ++L;
}
void moveTo (int l, int r)
{
    while(R<r)
        addr();
    while(l<L)
        addl();
    while(r<R)
        remr();
    while(L<l)
        reml();
}
void solve (int l, int r, int al, int ar)
{
    int mid = (l + r) / 2;
    int bst = ar;
    dp[mid]=1000000000;
    for(int i = min(mid, ar); i >= al; --i)
    {
        moveTo(i, mid);
        if(dp[mid] > S + dpv[i - 1])
        {
            dp[mid]=S+dpv[i-1];
            bst=i;
        }
    }
    if(l<=mid-1)
        solve(l,mid-1,al,bst);
    if(mid+1<=r)
        solve(mid+1,r,bst,ar);
}
int main()
{
    int n,i,a,x,k;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
    {
        nxtl[i]=lst[v[i]];
        lst[v[i]]=i;
    }
    for(i=1;i<=n;++i)
        lst[i]=n+1;
    for(i=n;i>=1;--i)
    {
        nxtr[i]=lst[v[i]];
        lst[v[i]]=i;
    }
    for(i=1;i<=n;++i)
        dpv[i]=1000000000;
    while(k--)
    {
        solve(1,n,1,n);
        for(i=1;i<=n;++i)
            dpv[i]=dp[i];
    }
    cout<<dp[n];
    return 0;
}