#include<bits/stdc++.h>
#define int long long
const int N=100005,mod=1e9+7;
using namespace std;

vector<int> d[N];
int sum[N];
int cnt[N];
void solve(){
	int n;cin>>n;
	int res=0;
	for(int i=N-1;i;i--){
		for(int j=i;j<N;j+=i)
			d[j].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int p=n-i;
		int s=d[p].size();
		for(int j=0;j<s;j++){
			cnt[j]=p/(d[p][j])-1;
			for(int k=0;k<j;k++)
				if(d[p][k]%d[p][j]==0)
					cnt[j]-=cnt[k];
			res+=cnt[j]*i*d[p][j]/__gcd(d[p][j],i)%mod;
		}
	} 
	cout<<res%mod<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}