#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,f[4000001];
inline int qp(int A,int P=n)
{
    register int Return=1;
    while(P)
    {
        if(P&1)
        {
            Return*=A;
            Return%=(int)(1e9+7);
        }
        A*=A;
        A%=(int)(1e9+7);
        P>>=1;
    }
    return Return%(int)(1e9+7);
}
signed main(){
	int k,now=0,ans=0;
	cin>>n>>k;
	for(int x=1,y;x<=k;x++)
	for(f[x]+=qp(x)-qp(x-1),now+=(f[x]%(int)(1e9+7)+(int)(1e9+7))%(int)(1e9+7),ans+=x^((now%(int)(1e9+7)+(int)(1e9+7))%(int)(1e9+7)),y=x*2;y<=k;y+=x)
	f[y]-=f[x];
	cout<<ans%(int)(1e9+7);
}