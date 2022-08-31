//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,aa;
llo it[200001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		cin>>n>>aa;
		llo st=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(st==0){
				if(it[i]>=(aa+1)/2 and it[i]<=aa){
					cout<<1<<endl;
					cout<<i+1<<endl;
					st=1;
				}
			}
		}
		if(st==0){
			vector<pair<llo,llo>> ss;
			for(llo i=0;i<n;i++){
				ss.pb({it[i],i});
			}
			sort(ss.begin(),ss.end());
			llo su=0;
			for(llo i=0;i<n;i++){
				su+=ss[i].a;
				if(st==0){
					
					if(su>=(aa+1)/2 and su<=aa){
						cout<<i+1<<endl;
						st=1;
						for(llo j=0;j<=i;j++){
							cout<<ss[j].b+1<<" ";
						}
						cout<<endl;
					}
				}
			}
			if(st==0){
				cout<<-1<<endl;
			}




		}
		





	}




 
 
	return 0;
}