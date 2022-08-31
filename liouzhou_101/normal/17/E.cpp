#include<cstdio>
#include<iostream>

using namespace std;

const int MaxN=4000010;
const int MOD=51123987;

int n;
char s[MaxN];
long long num,ans;
int a[MaxN],b[MaxN],F[MaxN];

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		scanf(" %c",&s[2*i]);
	s[0]='A';
	s[n*2+2]='B';
	for (int i=1,k,v=0;i<=2*n+1;++i)
	{
		F[i]=(i<v)?min(F[2*k-i],v-i):1;
		while (s[i-F[i]]==s[i+F[i]]) ++F[i];
		a[(i-F[i]+2)/2]++;
		a[i/2+1]--;
		b[(i+1)/2]++;
		b[(i+F[i])/2]--;
		(num+=F[i]/2)%=MOD;
		if (i+F[i]>v) v=i+F[k=i];
	}
	for (int i=1;i<=n;++i)
	{
		(a[i]+=a[i-1]+MOD)%=MOD;
		(b[i]+=b[i-1]+MOD)%=MOD;
	}
	for (int i=1;i<=n;++i)
	{
		(b[i]+=b[i-1])%=MOD;
		(ans+=(long long)a[i]*b[i-1])%=MOD;
	}
	cout<<((num*(num-1)/2-ans)%MOD+MOD)%MOD<<endl;
	return 0;
}