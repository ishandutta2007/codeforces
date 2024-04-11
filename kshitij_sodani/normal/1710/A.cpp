#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m,k;
		cin>>n>>m>>k;
		for(llo i=0;i<k;i++){
			cin>>it[i];
		}
		string ans="No";
		llo su=0;
		llo st=0;
		for(llo i=0;i<k;i++){
			llo x=it[i]/n;
			if(x>=2){
				if(x>=3){
					st=1;
				}
				su+=x;
			}
		}
		if(m%2==1){
			if(su>=m and st==1){
				ans="Yes";
			}
		}
		else if(su>=m){
			ans="Yes";
		}
		su=0;
		st=0;
		for(llo i=0;i<k;i++){
			llo x=it[i]/m;
			if(x>=2){
				su+=x;
				if(x>=3){
					st=1;
				}
			}
		}
		if(n%2==1){
			if(su>=n and st==1){
				ans="Yes";
			}
		}
		else if(su>=n){
			ans="Yes";
		}
		
		cout<<ans<<endl;

	}





	return 0;
}