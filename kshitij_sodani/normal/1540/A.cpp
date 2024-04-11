//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n;
llo t;
llo it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		sort(it,it+n);
		llo ans=it[n-1];
		llo su=0;
		for(llo i=1;i<n;i++){
			ans-=(i*(it[i])-su);
			su+=it[i];
		}
		cout<<ans<<endl;

		
	}









	return 0;
}