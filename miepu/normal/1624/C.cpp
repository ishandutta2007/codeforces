#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;cin>>n;vector<int>cnt(n+1);
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		while(x>n)x/=2;cnt[x]++;
	}
	int fl=1;
	for(int i=n;i;i--){
		if(!cnt[i])fl=0;
		cnt[i]--;
		cnt[i/2]+=cnt[i];
	}
	cout<<(fl?"YEs":"nO")<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}