
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

pair<llo,llo> it[100001];
llo dp[100001];
llo pre[100001];
llo tt[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo r,n;
	cin>>r>>n;
	it[0]={1,1};

	for(llo i=1;i<=n;i++){
		dp[i]=-n;
		//cout<<i<<"::::"<<endl;
		cin>>tt[i]>>it[i].a>>it[i].b;
		for(llo j=i-1;j>=max((llo)0,i-1000);j--){
			if(abs(it[j].a-it[i].a)+abs(it[j].b-it[i].b)<=tt[i]-tt[j]){
				dp[i]=max(dp[i],dp[j]+1);
			//	cout<<i<<":"<<j<<endl;
			//	cout<<it[j].a<<"::"<<it[i].a<<"::"<<it[j].b<<"::"<<it[i].b<<endl;
			//	cout<<abs(it[j].a-it[i].a)<<",,"<<abs(it[j].b-it[i].b)<<",,"<<tt[i]-tt[j]<<endl;

			}
			//cout<<i<<":"<<j<<endl;
		}
		if(i-1001>=0){
			dp[i]=max(dp[i],pre[i-1001]+1);
		}
		pre[i]=max(pre[i-1],dp[i]);
	//	cout<<dp[i]<<endl;
	}
/*	for(llo i=0;i<=n;i++){
		cout<<tt[i]<<","<<it[i].a<<","<<it[i].b<<endl;
	}*/
	cout<<pre[n]<<endl;


	return 0;
}