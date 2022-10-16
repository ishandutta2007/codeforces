#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,res=0;cin>>n;
	vector<int> a(n),fl(n),p;
	vector<int> dp(n,1e9);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<n-1;i++){
		if(a[i]>a[i-1]&&a[i]>a[i+1])fl[i]=1,p.push_back(i);
	}
	for(int i=0;i<p.size();i++){
		res++;
		if(i+1<p.size()&&p[i+1]==p[i]+2){
			a[p[i]+1]=max(a[p[i]],a[p[i+1]]);
			i++;
		}
		else a[p[i]]=max(a[p[i]-1],a[p[i]+1]);
	}
	cout<<res<<endl;
	for(auto x:a)cout<<x<<' ';cout<<endl;
}


main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}