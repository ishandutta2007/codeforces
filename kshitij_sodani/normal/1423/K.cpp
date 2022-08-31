
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

llo vis[1000001];
llo pre[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(llo i=2;i<=1000000;i++){
		if(vis[i]==0){
			vis[i]=1;
			for(llo j=i+i;j<=1000000;j+=i){
				vis[j]=2;
			}
		}
	}
	for(llo i=2;i<=1000000;i++){
		llo xx=i;
		if(vis[i]==1){
			xx*=xx;
		}
		if(xx<=1000000){
			pre[xx]+=1;
		}
	}
	for(llo j=1;j<=1000000;j++){
		pre[j]+=pre[j-1];
	}
	llo t;
	cin>>t;
/*	for(llo i=1;i<=10;i++){
		cout<<pre[i]<<":";
	}
	cout<<endl;*/
	while(t--){
		llo n;
		cin>>n;
		cout<<n-pre[n]<<endl;
	}


	return 0;
}