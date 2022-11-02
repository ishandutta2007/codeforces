#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,w[505],at;
struct node{int x,y,w;bool operator<(node b) const {return w>b.w;}}a[250005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(w[i]);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) a[++at]=(node){i,j,abs(w[i]-w[j])};
	sort(a+1,a+at+1);
	for(int i=1;i<=at;i++)
	{
		if(w[a[i].x]>w[a[i].y]) printf("? %d %d\n",a[i].x,a[i].y);
		else printf("? %d %d\n",a[i].y,a[i].x);
		fflush(stdout);
		string s;cin>>s;if(s=="Yes") return printf("! %d %d\n",a[i].x,a[i].y),0;
	}
	return puts("! 0 0"),0;
}