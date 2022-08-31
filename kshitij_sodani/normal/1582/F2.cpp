//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int val[8200];
int val2[8200];
vector<int> pre[5001];
vector<int> pre2[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<8200;i++){
		val[i]=n+1;
	}
	for(int i=0;i<n;i++){
		int aa;
		cin>>aa;
		pre[aa].pb(i);

	}
	val[0]=-1;
	for(int i=0;i<=5000;i++){
		if(pre[i].size()){
		//	set<int> ss;
			for(int j=0;j<8200;j++){
				val2[j]=val[j];
				/*if(val[j]>=-1){
					
					pre2[val[j]].pb(j);
					//ss.insert(val[j]);
				}*/
			}
			for(int j=0;j<8200;j++){
				if(val2[j]>=-1){
					int ind=lower_bound(pre[i].begin(),pre[i].end(),val2[j])-pre[i].begin();
					if(ind<pre[i].size()){
						val[j^i]=min(val[j^i],pre[i][ind]);
					}
				}
			}
			
		}
	}
	vector<int> ans;
	for(int i=0;i<8200;i++){
		if(val[i]<n){
			ans.pb(i);
		}
	}
	cout<<ans.size()<<endl;
	for(auto j:ans){
		cout<<j<<" ";
	}
	cout<<endl;
 
 
 

 
	return 0;
}