//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[200001];
llo vis[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo q;
	cin>>q;
	while(q--){
	//for(int n=200000;n<=200000;n++){
		int n;
		cin>>n;
		for(int i=0;i<=n;i++){
			vis[i]=0;
		}

		vector<int> ss;
		ss.pb(n);
		int cot=n;
		while(cot!=2){
			int cur=1;
			for(int i=1;;i++){
				if((cot+i-1)/i>=i){
					cur=i;
				}
				else{
					break;
				}
			//	cur=i;
			}
			cur=max(cur,2);
			ss.pb(cur);
			cot=(cot+cur-1)/cur;
		}
		for(auto j:ss){
			vis[j]=1;
		//	cout<<j<<",";
		}
		//cout<<endl;
		vector<pair<int,int>> ans;
		for(int i=n-1;i>=2;i--){
			if(vis[i]==0){
				ans.pb({i,n});
			}
		}
		cot=n;
		for(int j=1;j<ss.size();j++){
			int i=ss[j];
			ans.pb({n,i});
			cot=(cot+i-1)/i;
				if(cot==1){
					continue;
				}
				
			if(j+1<ss.size()){
				if(ss[j]==ss[j+1]){
					continue;
				}
			}
			ans.pb({i,n});
		
		}
	/*	for(int i=n-1;i>=2;i--){
			if(vis[i]==1){

				ans.pb({n,i});
				cot=(cot+i-1)/i;
				if(cot==1){
					continue;
				}
				ans.pb({i,n});
				
				//ans.pb({i,n});
			}
		}*/
		/*if(ans.size()>=n+5){
			cout<<n<<endl;
		}*/
		if(ans.size()>n+5){
			while(true){
				continue;
			}
		}
		cout<<ans.size()<<endl;
		for(auto j:ans){
			cout<<j.a<<" "<<j.b<<endl;
		}



	}






 
	return 0;
}