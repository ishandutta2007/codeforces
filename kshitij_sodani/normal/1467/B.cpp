 
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 
int it[300001];
int pre[300001];
int pre2[300001];
int cc(vector<int> dd){
	int co=0;
	for(int i=2;i<dd.size();i++){
		if(dd[i-1]>dd[i] and dd[i-1]>dd[i-2]){
			co+=1;
		}
		if(dd[i-1]<dd[i] and dd[i-1]<dd[i-2]){
			co+=1;
		}
	}
	return co;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>it[i];
			pre[i]=0;
			pre2[i]=0;
		}
		pre[n]=0;
		pre2[n]=0;
 
		if(n<3){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<n-2;i++){
			pre[i+2]=pre[i+1]+cc({it[i],it[i+1],it[i+2]});
		}
		for(int i=n-3;i>=0;i--){
			pre2[i]=pre2[i+1]+cc({it[i],it[i+1],it[i+2]});
		}
		int ans=min(pre[n-1],pre2[0]);
		for(int i=0;i<n;i++){
			int val=0;
			vector<int> kk;
			if(i>0){
				kk.pb(it[i-1]);
			}
			if(i<n-1){
				kk.pb(it[i+1]);
			}
			if(i>0){
				val+=pre[i-1];
			}
			val+=pre2[i+1];
 
			for(auto j:kk){
				vector<int> ee;
				for(int pp=-2;pp<=2;pp++){
					if(pp==0){
						ee.pb(j);
					}
					else{
						if(pp+i>=0 and pp+i<n){
							ee.pb(it[pp+i]);
						}
					}
				}
				ans=min(ans,cc(ee)+val);
			}
 
		}
		cout<<ans<<endl;
	}
 
 
 
 
 
 
 
 
 
	return 0;
}