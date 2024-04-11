#include<bits/stdc++.h>
using namespace std;
int const N=233333,M=26;
int n,tot,vis[N],in[N],cnt[N];
string s,t[N],ans;
vector<int>e[M];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<s.size();j++)
			cnt[s[j]-97]++;
		for(int j=1;j<s.size();j++)
			if(!e[s[j-1]-97].size())
				e[s[j-1]-97].push_back(s[j]-97),in[s[j]-97]++;
			else if(e[s[j-1]-97][0]!=s[j]-97)
				cout<<"NO\n",exit(0);
	}
	for(int i=0;i<M;i++)
		if(!in[i]&&cnt[i]){
			int p=i;t[tot]+=p+97;
			while(e[p].size()&&!vis[p])
				vis[p]=1,p=e[p][0],t[tot]+=p+97; 
			if(vis[p])
				cout<<"NO\n",exit(0);
			vis[p]=1;
			tot++; 
		}
	for(int i=0;i<M;i++)
		if(cnt[i]&&!vis[i]) 
			cout<<"NO\n",exit(0);
	sort(t,t+tot,[](string s,string t){return s+t<t+s;});
	for(int i=0;i<tot;i++)
		cout<<t[i];
	cout<<"\n";
}