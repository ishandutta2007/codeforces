#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo it[100001];
llo pre[100001][2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}

		vector<llo> x;
		if((n-2)%2==1){
			x.pb(1);
		}
		else{
			x.pb(1);
			x.pb(2);
		}
		llo ans=1e18;
		for(auto j:x){
			llo su=0;
			for(llo i=j;i<n-1;i+=2){

				su+=max(max(it[i-1],it[i+1])-it[i]+1,(llo)0);
			}
			ans=min(ans,su);
		}
		if(n%2==0){
			for(llo i=1;i<n-1;i++){
				pre[i][0]=pre[i-1][0];
				pre[i][1]=pre[i-1][1];
				if(i%2==0){
					pre[i][0]+=max(max(it[i-1],it[i+1])-it[i]+1,(llo)0);
				}
				else{
					pre[i][1]+=max(max(it[i-1],it[i+1])-it[i]+1,(llo)0);
				}
			}
			for(llo i=2;i<n-2;i+=2){
				ans=min(ans,pre[i][1]+pre[n-2][0]-pre[i][0]);
			}
		}
		
		cout<<ans<<endl;

	}






	return 0;
}