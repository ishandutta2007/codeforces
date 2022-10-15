#include <bits/stdc++.h>
using namespace std;
void solve(){
	int N,K,s=0;
	cin>>N>>K;
	int arr[169];
	vector<int> v(N);
	iota(v.begin(),v.end(),1);
	for(int i=0,u;i<K;i++){
		cin>>u;
		(s+=u)%=v.size();
		cout<<v[s]<<" ";
		v.erase(v.begin()+s);
	}
}
int main(){
	int T=1;
	//cin>>T;
	while(T--)solve();
}