#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int n,m=100;
string s;
vector<string> V;
inline string nxt(string s)
{
	string res;
	int n=(int)s.size();
	register int i;
	for(i=0;i<n;i++)
		if(s[i]!='z')
			goto end;
	for(i=0;i<n+1;i++)
		res.push_back('a');
	return res;
	end:;
	for(i=n-1;i>=0;i--)
		if(s[i]<'z')
			return s[i]++,s;
		else
			s[i]='a';
}
inline void solve()
{
	register int i,j;
	cin>>n>>s;V.clear();
	for(i=1;i<=m&&i<=n;i++)
		for(j=0;j+i<=n;j++)
			V.push_back(s.substr(j,i));
//	for(string s:V)
//		cout<<s<<endl;
	sort(V.begin(),V.end(),[](string &a,string &b)->bool
	{
		if((int)a.size()!=(int)b.size())
			return a.size()<b.size();
		return a<b;
	});
//	for(string s:V)
//		cout<<s<<endl;
	int _=unique(V.begin(),V.end(),[](string &a,string &b)->bool
	{
		return a==b;
	})-V.begin();
//	for(string s:V)
//		cout<<s<<endl;
	while((int)V.size()>_)
		V.pop_back();
	if(V[0]!="a")
		return cout<<"a"<<endl,void();
	for(i=1;i<(int)V.size();i++)
		if(V[i]!=nxt(V[i-1]))
			return cout<<nxt(V[i-1])<<endl,void();
	cout<<nxt(V.back())<<endl;
	return;
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}