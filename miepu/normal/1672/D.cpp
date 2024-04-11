#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> cnt(n+1),a(n),b(n);
	for(auto&x:a)cin>>x;
	for(auto&x:b)cin>>x;
	for(int i=0,j=0,pr=-1;i<n;i++){
		int x=b[i];
		if(x==pr&&cnt[x]){
			cnt[x]--;
			continue;
		}
		while(j<n&&a[j]!=b[i]){
			cnt[a[j]]++;
			j++;
		}
		if(j==n){
			cout<<"NO"<<endl;
			return;
		}
		j++;
		pr=b[i];
	}
	cout<<"YES"<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}