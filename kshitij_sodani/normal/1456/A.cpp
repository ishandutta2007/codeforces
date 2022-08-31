//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[100001];
llo pre[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,p,k;
		cin>>n>>p>>k;
		string s;
		cin>>s;
		llo x,y;
		cin>>x>>y;
		for(llo i=0;i<n;i++){
			if(s[i]=='1'){
				it[i]=1;
			}
			else{
				it[i]=0;
			}
		}
		for(llo i=n-1;i>=0;i--){
			if(i+k<n){
				pre[i]=pre[i+k]+1-it[i];
			}
			else{
				pre[i]=1-it[i];
			}
		}
		llo cur=0;
		llo ans=1e9;
		for(llo i=0;i<n;i++){
			cur++;
			//if(it[i]==1){
			//	cur++;
				if(cur>=p){
				//	cout<<i<<":"<<cur-p+pre[i]<<endl;
					ans=min(ans,y*(cur-p)+x*pre[i]);
				}
			//}
		}
		cout<<ans<<endl;
	}



 
 
	return 0;
}