#include<bits/stdc++.h>
using namespace std;
int const N=233;
int n,m,x,q,ans,d[N];
string s;
char a[N][N];
vector<pair<int,int> >t[N]; 
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	cin>>q>>s;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			t[a[i][j]].push_back({i,j});
	memset(d,0x3f,sizeof d);
	for(char i='a';i<='z';i++)
		for(auto p1:t[i])
			for(auto p2:t['S'])
				d[i]=min(d[i],(p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
	for(int i=0;i<q;i++){
		if(islower(s[i])){
			if(t[s[i]].empty())
				cout<<"-1\n",exit(0);
		}else{
			char c=tolower(s[i]);
			if(t[c].empty()||t['S'].empty())
				cout<<"-1\n",exit(0);
			ans+=d[c]>x*x;
		}
	}
	cout<<ans<<"\n";
}