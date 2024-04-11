#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,vis[N];
vector<int>t;
vector<pair<int,int> >ans;
int isprime(int x){
    if(x<2)return 0;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)return 0;
	return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
	for(int i=n>>1;i>=2;i--)
		if(isprime(i)){
			int cnt=0;
			for(int j=i;j<=n;j+=i)cnt+=!vis[j];
			t.clear();
			for(int j=i;j<=n;j+=i)
				if((~cnt&1||j!=2*i)&&!vis[j])
				    vis[j]=1,t.push_back(j);
			for(int i=0;i<t.size()/2*2;i+=2)
				ans.emplace_back(t[i],t[i+1]);
		}
	cout<<ans.size()<<"\n";
	for(auto i:ans)
	    cout<<i.first<<" "<<i.second<<"\n";
}