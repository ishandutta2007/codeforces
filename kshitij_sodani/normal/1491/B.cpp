//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,u,v;
		cin>>n>>u>>v;
		vector<llo> ss;
		llo st=1;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			ss.pb(it[i]);
			if(i>0){
				if((abs(it[i]-it[i-1]))>1){
					st=0;
				}
			}
		}
		sort(ss.begin(),ss.end());
		if(st==0){
			cout<<0<<endl;
		}
		else if(abs(ss[0]-ss[n-1])==0){
			cout<<min(2*v,u+v)<<endl;
			
		}
		else{
			cout<<min(u,v)<<endl;
		}

	}


 
	return 0;
}