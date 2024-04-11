//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo aa[100001];
llo bb[100001];
llo pre[100001];
llo pre2[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>aa[i];
		}
		for(llo i=0;i<n;i++){
			cin>>bb[i];
		}
		sort(aa,aa+n);
		sort(bb,bb+n);
		for(llo i=0;i<n/2;i++){
			swap(aa[i],aa[n-i-1]);
			swap(bb[i],bb[n-i-1]);
		}
		//pre[0]=0;
		for(llo i=1;i<=n;i++){
			pre[i]=pre[i-1]+aa[i-1];
			pre2[i]=pre2[i-1]+bb[i-1];
		}
		for(llo i=0;i<=n;i++){
			llo x=(n+i)-((n+i)/4);
			llo su=0;
			llo su2=0;
			su+=100*min(i,x);
			llo le=x-min(i,x);
			su+=pre[le];
			le=min(x,n);
			su2+=pre2[le];
			if(su>=su2){
				cout<<i<<endl;
				break;
			}

		}
	}

 
 
 
 
 
 
 
	return 0;
}