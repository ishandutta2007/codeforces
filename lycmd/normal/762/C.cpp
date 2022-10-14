#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,m,ans,a1,a2,pre[N][27],nxt[N][27];
string s,t;
vector<pair<int,int> >p1,p2;
int main(){
	cin>>s>>t;
	n=s.size(),m=t.size(),s=" "+s;
	for(int i=0;i<26;i++)
		pre[0][i]=0,nxt[n+1][i]=n+1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<26;j++)
			pre[i][j]=j+97==s[i]?i:pre[i-1][j];
	for(int i=n;i>=1;i--)
		for(int j=0;j<26;j++)
			nxt[i][j]=j+97==s[i]?i:nxt[i+1][j];
	p1.push_back({-1,-1});
	for(int i=0,p=0;i<m;i++){
		p=nxt[p+1][t[i]-97];
		if(p>n)break;
		p1.push_back({p,i});
	}
	for(int i=m-1,p=n+1;~i;i--){
		p=pre[p-1][t[i]-97];
		if(p<1)break;
		p2.push_back({p,i});
	}
	reverse(p2.begin(),p2.end());
	p2.push_back({n+1,m});
	if(p1.size()==1&&p2.size()==1)
		cout<<"-\n",exit(0);
	for(auto i:p1){
		auto t=*upper_bound(p2.begin(),p2.end(),make_pair(i.first,m));
		int pl=i.second,pr=max(pl+1,t.second);
		if(pl+1+m-pr>ans)
			ans=pl+1+m-pr,a1=pl,a2=pr;
	}
	cout<<t.substr(0,a1+1)+t.substr(a2)<<"\n";
}