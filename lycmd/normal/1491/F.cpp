#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
vector<int>ans;
int ask(int p,int l,int r=-1){
	if(!~r)r=l;
	cout<<"? 1 "<<r-l+1<<endl<<p<<endl;
	for(int i=l;i<=r;i++)
		cout<<i<<" ";
	cout<<endl,cin>>p;
	return p;
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n,ans.clear();
		int p=2,l=0,r;
		while(!ask(p,1,p-1))p++;
		r=p-1;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(ask(p,1,mid))r=mid;else l=mid;
		}
		for(int i=1;i<p;i++)
			if(i!=r)
				ans.push_back(i);
		for(int i=p+1;i<=n;i++)
			if(!ask(p,i))
				ans.push_back(i);
		cout<<"! "<<ans.size();
		for(int x:ans)cout<<" "<<x;
		cout<<endl;
	}
}