//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo n;
llo it[200010];
llo pre[200010];
llo pre2[200010];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		
	}
	if(n==1){
		cout<<it[0]<<endl;
		return 0;
	}
	for(llo i=0;i<n;i++){
		pre[i]=it[i];
		if(i>=2){
			pre[i]+=pre[i-2];
		}
	}
	for(llo i=n-1;i>=0;i--){
		pre2[i]=pre2[i+2]+it[i];
	}
	llo ans=0;
	for(llo i=0;i<n-1;i++){
		ans=max(ans,pre2[i+1]+pre[i]);

	}
	ans=max(ans,pre[n-1]);
	cout<<ans<<endl;















 
	return 0;
}