#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,ans,a[N];
map<pair<int,int>,int>cnt;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1,t=0;j<n;j++){
			if((t+=a[j])>=a[i]*2)
				break;
			if(t==(a[i]^a[j+1]))
				ans+=cnt[{i,j+1}]=1;
		}
		for(int j=i-1,t=0;j>1;j--){
			if((t+=a[j])>=a[i]*2)
				break;
			if(t==(a[i]^a[j-1]))
				ans+=1-cnt[{j-1,i}];
		}
	}
	cout<<ans<<"\n";
}//