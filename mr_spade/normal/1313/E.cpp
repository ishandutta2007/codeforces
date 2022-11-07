#include<bits/stdc++.h>
#define int long long
using namespace std;
inline vector<int> exkmp(string s)
{
	int n=(int)s.size(),pos=-1;
	vector<int> z;
	register int i;
	z.resize(n);
	for(i=1;i<n;i++)
	{
		if(~pos&&pos+z[pos]-1>=i)
			z[i]=min(z[i-pos],pos+z[pos]-i);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])
			z[i]++;
		if(!~pos||i+z[i]>pos+z[pos])
			pos=i;
	}
	return z;
}
inline vector<int> run(string s,vector<int> z,string t)
{
	int n=(int)s.size(),m=(int)t.size(),pos=-1;
	vector<int> ans;
	register int i;
	ans.resize(m);
	for(i=0;i<m;i++)
	{
		if(~pos&&pos+ans[pos]-1>=i)
			ans[i]=min(z[i-pos],pos+ans[pos]-i);
		while(ans[i]<n&&i+ans[i]<m&&s[ans[i]]==t[i+ans[i]])
			ans[i]++;
		if(!~pos||i+ans[i]>pos+ans[pos])
			pos=i;
	}
	return ans;
}
const int N=1e6+5;
int n,m,ans;
int bit[N],bit2[N];
string a,b,s,rb,rs;
vector<int> va,vb;
inline void add(int x,int k)
{
	int y=x;
	while(x<=m)
		bit[x]+=k,bit2[x]+=y*k,x+=x&-x;
	return;
}
inline int ask(int x)
{
	int res=0;
	while(x)
		res+=bit[x],x&=x-1;
	return res;
}
inline int ask2(int x)
{
	int res=0;
	while(x)
		res+=bit2[x],x&=x-1;
	return res;
}
signed main()
{
	int c1,c2;
	register int i;
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>a>>b>>s;
	rb=b;reverse(rb.begin(),rb.end());
	rs=s;reverse(rs.begin(),rs.end());
	va=run(s,exkmp(s),a);
	reverse(va.begin(),va.end());va.push_back(0);
	reverse(va.begin(),va.end());
	vb=run(rs,exkmp(rs),rb);vb.push_back(0);
	reverse(vb.begin(),vb.end());
	for(i=1;i<=n;i++)
		va[i]=min(va[i],m-1),vb[i]=min(vb[i],m-1);
	for(i=1;i<=n&&i<=m-1;i++)
		if(vb[i])
			add(vb[i],1);
	for(i=1;i<=n;i++)
	{
		c1=ask(m)-ask(m-va[i]-1);
		c2=ask2(m)-ask2(m-va[i]-1);
		ans+=(va[i]-m+1)*c1+c2;
		if(i<n)
		{
			if(vb[i])
				add(vb[i],-1);
			if(i+m-1<=n&&vb[i+m-1])
				add(vb[i+m-1],1);
		}
	}
	cout<<ans<<endl;
	return 0;
}