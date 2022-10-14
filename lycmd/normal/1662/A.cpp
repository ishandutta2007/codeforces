#include<bits/stdc++.h>
using namespace std;
int const N=233;
int t,n,a[N];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		memset(a,-1,sizeof a);
		for(int i=1;i<=n;i++){
			int b,d;cin>>b>>d;
			a[d]=max(a[d],b);
		}
		int flg=1,ans=0;
		for(int i=1;i<=10;i++)
			flg&=a[i]>=0,ans+=a[i];
		if(!flg)cout<<"MOREPROBLEMS\n";
		else cout<<ans<<"\n";
	}
}