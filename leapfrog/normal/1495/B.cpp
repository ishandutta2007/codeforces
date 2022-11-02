//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[100005],le[100005],ri[100005],T[100005],cn,res=0;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	le[1]=0;for(int i=2;i<=n;i++) if(a[i]>a[i-1]) le[i]=le[i-1]+1;else le[i]=0;
	ri[n]=0;for(int i=n-1;i;i--) if(a[i]>a[i+1]) ri[i]=ri[i+1]+1;else ri[i]=0;
	cn=0;for(int i=1;i<=n;i++) T[++cn]=max(le[i],ri[i]);
	sort(T+1,T+cn+1,greater<int>());if(T[1]==T[2]) return puts("0"),0;
	int ln=T[1];for(int i=2;i<n;i++) if(le[i]&&ri[i]&&le[i]==ri[i]&&le[i]%2==0&&le[i]==ln) res++;
	return printf("%d\n",res),0;
}