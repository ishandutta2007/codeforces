#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,k,a,q,cur;
set<int>s;
int calc(int l,int r){
	return (r-l)/(a+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k>>a,cur=calc(0,n+1);
	s.insert(0),s.insert(n+1);
	cin>>q;
	for(int i=1;i<=q;i++){
		int x;cin>>x;
		int l=*--s.lower_bound(x),r=*s.lower_bound(x);
		cur+=calc(l,x)+calc(x,r)-calc(l,r);
		s.insert(x);
		if(cur<k)cout<<i<<"\n",exit(0);
	}
	cout<<"-1\n";
}