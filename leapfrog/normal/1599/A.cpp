//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int n,a[200005];char ch[200005],fg[200005];
vector<int>vc;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	scanf("%s",ch+1),fg[n]=ch[n];int l=1,r=n;sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--) fg[i]=fg[i+1]^'L'^'R';
	//printf("%s\n%s\n",ch+1,fg+1);
	for(int i=n-1;i>=1;i--) vc.push_back(fg[r]==ch[i]?l++:r--);
	//for(auto x:vc) printf("%d ",x);putchar('\n');
	vc.push_back(l),reverse(vc.begin(),vc.end());ll vl=0,vr=0;
	int qwq=0;for(auto i:vc)
	{
		(fg[i]=='L'?vl:vr)+=a[i],++qwq;
		if(vl==vr||((vl>vr)^(ch[qwq]=='L'))) return puts("-1"),0;
	}
	for(auto i:vc) printf("%d %c\n",a[i],fg[i]);
	return 0;
}