#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,x;
int cnt[N];

void solve(){
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		int y;cin>>y;
		cnt[y]++;
	}
	for(int i=1;i<x;i++){
		if(cnt[i]%(i+1)){
			cout<<"NO"<<endl;
			exit(0);
		}
		cnt[i+1]+=cnt[i]/(i+1);
	}
	cout<<"YES"<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}