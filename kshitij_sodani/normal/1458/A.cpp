//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,m;
llo aa[200001];
llo bb[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(llo i=0;i<n;i++){
		cin>>aa[i];
	}
	for(llo i=0;i<m;i++){
		cin>>bb[i];
	/*	llo ans=bb[i]+aa[0];
		for(llo j=0;j<n;j++){
			ans=__gcd(ans,bb[i]+aa[j]);
		}
		cout<<ans<<" ";*/
	//	cout<<bb[i]+1<<" ";
	}
	if(n==1){
		for(llo j=0;j<m;j++){
			cout<<bb[j]+aa[0]<<" ";
		}
		cout<<endl;
		return 0;
	}
	sort(aa,aa+n);
	llo xx=aa[1]-aa[0];
	

	for(llo i=1;i<n-1;i++){
		xx=__gcd(xx,aa[i+1]-aa[i]);
	}
	for(llo i=0;i<n;i++){
		cout<<__gcd(bb[i]+aa[0],xx)<<" ";
	}
	cout<<endl;
	//cout<<endl;





 
	return 0;
}