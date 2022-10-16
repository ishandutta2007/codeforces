#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int fst=1,pos;
	while(fst<n&&a[fst-1]==fst)fst++;
	for(int i=0;i<n;i++){
		if(a[i]==fst){
			pos=i;break;
		} 
	}
	reverse(a.begin()+fst-1,a.begin()+pos+1);
	for(auto x:a)cout<<x<<' ';
	cout<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}