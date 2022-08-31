//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo t;
llo it[2001];
llo pre[2001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		pre[0]=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			pre[i+1]=pre[i]^it[i];
		}
		llo st=1;
		for(llo i=0;i<n-1;i++){
			if(pre[n]==0){
				st=0;
			}
			for(llo j=i+1;j<n-1;j++){
				if(pre[i+1]==pre[n] and pre[j+1]==0){
					st=0;
				}
			}
		}
		if(st==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}





 
 
	return 0;
}