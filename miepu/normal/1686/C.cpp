#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

int n;
void solve(){
	cin>>n;
	vector<int> a(n);
	map<int,int> c;
	int mx=0;
	for(auto &x:a){
		cin>>x;
		c[x]++;
		mx=max(mx,c[x]);
	}
	if(n&1){
		cout<<"NO"<<endl;
		return;
	}
	if(mx*2>n){
		cout<<"NO"<<endl;
		return;
	}
	sort(a.begin(),a.end()); 
	vector<int>b;
	for(int i=0;i<n/2;i++)
		b.push_back(a[i]),b.push_back(a[n/2+i]);
	int flag=1;
	for(int i=0;i<n;i++){
		flag&=(b[i]>b[(i-1+n)%n])&&(b[i]>b[(i+1)%n])||(b[i]<b[(i-1+n)%n])&&(b[i]<b[(i+1)%n]);
	}
	if(!flag){
		cout<<"NO"<<endl;
		return ; 
	}
	cout<<"YES"<<endl;
	for(auto x:b)cout<<x<<' ';
	cout<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}