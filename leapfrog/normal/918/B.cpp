//Coded by Kamiyama_Shiki on 2021.11.09 {{{
//
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
int n,m;map<string,string>mp;
int main()
{
	read(n,m);
	for(int i=1;i<=n;i++)
	{
		string a,b;cin>>a>>b;
		mp[b]=a;
	}
	for(int i=1;i<=m;i++)
	{
		string a,b;cin>>a>>b;
		b=b.substr(0,b.size()-1);
		cout<<a<<" "<<b<<"; #"<<mp[b]<<endl;
	}return 0;
}