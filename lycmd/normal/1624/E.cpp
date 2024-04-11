#include<bits/stdc++.h>
using namespace std;
int const N=1010;
int T,n,m,f[N];
string s,t;
array<int,3>p[N];
map<string,array<int,3> >a[4];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>T;T--;){
		cin>>n>>m;
		a[2].clear(),a[3].clear();
		for(int i=1;i<=n;i++){
			cin>>t,t=" "+t;
			for(int l=2;l<=3;l++)
				for(int p=1;p<=m-l+1;p++)
					a[l][t.substr(p,l)]={p,p+l-1,i};
		}
		cin>>s,s=" "+s;
		for(int i=1;i<=m;i++)
			f[i]=0;
		f[0]=1;
		for(int i=1;i<=m;i++)
			for(int l=2;l<=min(i,3)&&!f[i];l++)
				for(auto j:a[l])
					if(f[i-l]&&s.substr(i-l+1,l)==j.first)
						f[i]=1,p[i]=j.second;
		if(!f[m])
			cout<<"-1\n";
		else{
			vector<array<int,3> >v;
			for(int i=m;i;i-=p[i][1]-p[i][0]+1)
				v.push_back(p[i]);
			reverse(v.begin(),v.end());
			cout<<v.size()<<"\n";
			for(auto i:v)
				cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
		}
	}
}