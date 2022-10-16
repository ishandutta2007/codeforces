#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int a[N]; 
int res[N];
void solve(){
	int n;cin>>n;
	vector<pair<int,int>> A;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			A.push_back({a[i]-a[i+1],i+1});
		}
	}
	sort(A.begin(),A.end());
	reverse(A.begin(),A.end());
	for(int i=1;i<=n;i++)res[i]=1;
	for(int i=0;i<A.size();i++)res[n-i]=A[i].second;
	for(int i=1;i<=n;i++)cout<<res[i]<<' ';
	cout<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}