//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		llo cur=-1;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		for(llo i=0;i<m;i++){
			llo x;
			cin>>x;
			if(i==0){
				cur=x;
			}
			cur=__gcd(cur,x);
		}
		//cout<<cur<<"::"<<endl;
		llo ans=-1e18;
		for(llo i=0;i<2;i++){
			llo ans2=0;
			for(llo k=0;k<cur;k++){
				llo st=0;
				for(llo j=k;j<n;j+=cur){
					if(it[j]<0){
						st^=1;
					}
				}
				for(llo j=k;j<n;j+=cur){
					ans2+=abs(it[j]);
				}
				if(st==i){
				
				}
				else{
					llo mi=1e9;
					for(llo j=k;j<n;j+=cur){
						mi=min(mi,(llo)abs(it[j]));
					}
					ans2-=2*mi;
				}
			}
			ans=max(ans,ans2);
		}
		cout<<ans<<endl;
	}




 
	return 0;
}