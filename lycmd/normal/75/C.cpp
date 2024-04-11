#include<bits/stdc++.h>
using namespace std;
int a,b,t;
vector<int>v;
int main(){
	ios::sync_with_stdio(0);
	cin>>a>>b>>t;
	int k=__gcd(a,b);
	for(int i=1;i*i<=k;i++)
		if(k%i==0)v.push_back(i),v.push_back(k/i);
	sort(v.begin(),v.end());
	while(t--){
		int x,y,flg=0;cin>>x>>y;
		for(int i=v.size()-1;!flg&&i>=0;i--)
			if(x<=v[i]&&v[i]<=y)
				cout<<v[i]<<"\n",flg=1;
		if(!flg)cout<<-1<<"\n";
	}
}