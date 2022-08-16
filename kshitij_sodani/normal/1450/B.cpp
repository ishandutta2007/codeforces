//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo aa[101];
llo bb[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		for(llo i=0;i<n;i++){
			cin>>aa[i]>>bb[i];
		}
		llo ans=-1;
		for(llo i=0;i<n;i++){
			llo cur=0;
			llo st=1;
			for(llo j=0;j<n;j++){
				if(abs(aa[i]-aa[j])+abs(bb[i]-bb[j])<=k){

				}
				else{
					st=0;
				}
			}
			if(st==1){
				ans=1;
			}

		}
		cout<<ans<<endl;

	}















 
	return 0;
}