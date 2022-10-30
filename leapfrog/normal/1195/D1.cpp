//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
const int P=998244353;int n,a[100005],ln[100005],pw[55],cn[15],rs=0;
inline int count(int x) {int r=0;while(x) x/=10,r++;return r;}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),ln[i]=count(a[i]);
	pw[0]=1;for(int i=1;i<=50;i++) pw[i]=10ll*pw[i-1]%P;
	for(int i=1;i<=n;i++) cn[ln[i]]++;
	for(int i=1;i<=n;i++)
	{
		int g[15],x=a[i],gt=0;while(x) g[gt++]=x%10,x/=10;
		for(int k=0;k<=10;k++) for(int j=0;j<ln[i];j++)
			rs=(rs+1ll*(pw[j+min(j,k)]+pw[j+min(j+1,k)])*g[j]%P*cn[k])%P;
	}
	return printf("%d\n",rs),0;
}