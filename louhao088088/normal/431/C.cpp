#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int f1[105],f2[105],n,d,k;
int main()
{
	cin>>n>>k>>d;f1[0]=f2[0]=1;
    for(int i=1;i<=n;i++)
	{
        for(int j=max(0,i-k);j<i;j++)f1[i]=(f1[i]+f1[j])%mod;
        for(int j=max(0,i-d+1);j<i;j++)f2[i]=(f2[i]+f2[j])%mod;
    }
    printf("%d\n",((f1[n]-f2[n]+mod)%mod));
    return 0;
}