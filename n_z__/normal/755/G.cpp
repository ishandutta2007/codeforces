#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
tuple<int,int,int>q[100001];
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
void init(int n)
{
    q[0]=make_tuple(1,n,1);
	for(int x=1,fk,ccf;x<=100000;x++)
    fk=get<0>(q[x-1])*qp(x,p-2)%p,ccf=get<1>(q[x-1]),q[x]=make_tuple(fk,ccf*(n-x)%p,fk*qp(ccf,p-2)%p);
}
main()
{
    int n,k;
	cin>>n>>k;
    init(n);
	for(int x=1;x<=k;x++)
	{
		int ans=0;
		for(int y=0,z=min(x,n-x);y<=z;y++)
		ans+=get<1>(q[x+y-1])*get<2>(q[y])%p*get<0>(q[x-y])-996491788296388609,ans+=ans>>63&996491788296388609;
		cout<<ans%p<<' ';
	}
}