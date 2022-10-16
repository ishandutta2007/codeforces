#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1e9+7;
inline int qp(int A,int P,int MOD=p)
{
    register int Return=1;
    while(P)
    {
        if(P&1)
        {
            Return*=A;
            Return%=MOD;
        }
        A*=A;
        A%=MOD;
        P>>=1;
    }
    return Return%MOD;
}
int inv[200001],jc[200001];
main()
{
    int t;
    cin>>t;
    inv[0]=jc[0]=1;
    for(int x=1;x<=200000;x++)
    jc[x]=jc[x-1]*x%p,inv[x]=inv[x-1]*qp(x,p-2)%p;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(n%2==0){
            int s=0,ss=0;
            for(int x=0;x<n;x+=2)
            s+=inv[x]*jc[n]%p*inv[n-x]%p,s%=p;
            for(int x=0;x<=n;x++)
            ss+=inv[x]*jc[n]%p*inv[n-x]%p,ss%=p;
            int ans=0;
            int now=1;
            for(int x=1;x<=k;x++)
            {
                ans+=now*qp(ss,k-x)%p;
                ans%=p;
                now*=s;
                now%=p;
            }
            cout<<(ans+now)%p<<endl;
        }
        else{
            int s=0;
            for(int x=0;x<n;x+=2)
            s+=inv[x]*jc[n]%p*inv[n-x]%p,s%=p;
            s++,s%=p;
            cout<<qp(s,k)<<endl;
        }
    }
}