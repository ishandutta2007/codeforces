#include<bits/stdc++.h>
#define int long long
const int N=100050;
using namespace std;

int n,k,a[N],b[N];

vector<int> A[N];
void solve(){
	cin>>n>>k;
	int mx=0;
	for(int i=1;i<=100000;i++)A[i].clear();
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=k;
		A[a[i]/b[i]].push_back(i);
		mx=max(mx,a[i]/k);
	}
	int res=mx;
	for(int mn=0;mn<a[1];mn++){
		for(auto x:A[mn]){
			b[x]=a[x]/(mn+1);
			mx=max(mx,a[x]/b[x]);
			A[a[x]/b[x]].push_back(x);
		}		
		res=min(res,mx-mn-1);
		vector<int> nw;
		swap(nw,A[mn]);
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}