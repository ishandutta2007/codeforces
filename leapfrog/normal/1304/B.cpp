//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,z[10005],q[10005],f[10005],id;string s[100005];map<string,int>mp;
int main()
{
	read(n),read(m);int zt=0,ft=0,id=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];string t="";for(int j=0;j<(int)s[i].size();j++) t=s[i][j]+t;
		if(id==-1&&t==s[i]) {id=i;continue;}
		if(mp[t]) z[++zt]=mp[t],f[++ft]=i,mp[t]=0;else mp[s[i]]=i;
	}
	printf("%d\n",(zt+(id!=-1)+ft)*m);
	for(int i=1;i<=zt;i++) cout<<s[z[i]];
	if(id!=-1) cout<<s[id];
	for(int i=ft;i>=1;i--) cout<<s[f[i]];
	return cout<<endl,0;
}