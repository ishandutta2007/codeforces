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
		sort(it,it+n);
		llo cur=0;
		for(llo i=0;i<n;i++){
			if(it[i]<=0){
				cur++;
			}
		}
		if(cur==n){
			cout<<cur<<endl;
			continue;
		}
		vector<llo> ss;
		for(llo i=0;i<cur;i++){
			if(ss.size()==0){
				ss.pb(it[i]);
				continue;
			}
			if(it[i]-ss.back()>=it[cur]){
				ss.pb(it[i]);
			}
		}
		cout<<max((llo)ss.size()+1,cur)<<endl;
		
 
	}
 
 
 
 
 
 
 
	return 0;
}