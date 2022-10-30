//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
string s,rs[100005];int n;map<string,int>mp;
int main()
{
	read(n);for(int i=1;i<=n;i++)
	{
		cin>>s;for(int j=0;j<9;j++)
			for(int k=1;k<=9-j;k++)
			{
				int &w=mp[s.substr(j,k)];
				if(!w) w=i;else if(w^i) w=-1;
			}
	}
	for(int i=1;i<=n;i++) rs[i]="1145141919810";
	for(auto x:mp) if(~x.second&&rs[x.second].size()>x.first.size()) rs[x.second]=x.first;
	for(int i=1;i<=n;i++) cout<<rs[i]<<endl;
	return 0;
}