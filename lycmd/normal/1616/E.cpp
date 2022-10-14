#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,tr[N];
vector<int>p[33];
string a,b;
void add(int x,int y=1){
	if(x<=n)tr[x]+=y,add(x+(x&-x),y);
}
int ask(int x){
	return x?ask(x&x-1)+tr[x]:0;
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>a>>b,a=" "+a,b=" "+b;
		for(int i=1;i<=n;i++)
			tr[i]=0;
		for(int i=0;i<26;i++)
			p[i].clear();
		for(int i=n;i;i--)
			p[a[i]-97].push_back(i),add(i);
		int ans=n*n,cur=0;
		for(int i=1;i<=n;i++){
			int t=b[i]-97;
			for(int j=0;j<t;j++)
				if(!p[j].empty())
					ans=min(ans,cur+ask(p[j].back()-1));
			if(p[t].size())
				cur+=ask(p[t].back()-1),
				add(p[t].back(),-1),p[t].pop_back();
			else break;
		}
		cout<<(ans<n*n?ans:-1)<<"\n";
	}
}