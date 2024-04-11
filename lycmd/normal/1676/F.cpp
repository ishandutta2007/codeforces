#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,k,a[N];
map<int,int>cnt;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>k,cnt.clear();
		for(int i=1;i<=n;i++)
			cin>>a[i],cnt[a[i]]++;
		int res=0,cur=0,pre=-1,pp=-1;
		for(auto i:cnt){
			if(i.second<k)continue;
			if(i.first==pre+1)cur++;
			else cur=1;
			if(cur>res)res=cur,pp=i.first;
			pre=i.first;
		}
		if(!res)cout<<"-1\n";
		else cout<<pp-res+1<<" "<<pp<<"\n"; 
	}
	return 0;
}