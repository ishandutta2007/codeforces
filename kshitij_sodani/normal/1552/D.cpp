//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[11];
llo dp[1<<11];
llo xx[1<<11];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	for(llo i=1;i<(1<<10);i++){
		for(llo j=0;j<10;j++){
			if((1<<j)&i){
				xx[i]=j;
				break;
			}
		}
	}
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		llo st=0;
		for(llo i=1;i<(1<<n);i++){
			vector<llo> ss;
			llo su=0;
			for(llo j=0;j<n;j++){
				if((1<<j)&i){
					su+=it[j];
					ss.pb(j);
				}
			}
			for(llo j=0;j<(1<<ss.size());j++){
				dp[j]=0;
				if(j>0){
					dp[j]=it[ss[xx[j]]]+dp[j-(1<<xx[j])];
				}
				if(dp[j]-(su-dp[j])==0){
					st=1;
					cout<<"YES"<<endl;
					break;
				}
			}
			if(st){
				break;
			}

		}
		if(st==0){
			cout<<"NO"<<endl;
		}
	}
 
 

 
 
 
	return 0;
}