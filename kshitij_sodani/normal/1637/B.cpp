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
		llo n;
		cin>>n;
		llo ans=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			llo cur=1;
			if(it[i]==0){
				cur++;
			}
			ans+=((i+1)*(n-i))*cur;
		}
		cout<<ans<<endl;
	}



	


 
	return 0;
}