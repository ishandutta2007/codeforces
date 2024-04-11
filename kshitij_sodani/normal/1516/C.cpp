//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define endl '\n'
#define b second
llo n;
llo it[20001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	llo su2=0;	
	for(llo i=0;i<n;i++){
		cin>>it[i];
		su2+=it[i];
	}
	if(su2%2==0){
		bitset<2000*101> xx;
		xx[0]=1;
		for(int j=0;j<n;j++){
			xx|=(xx<<it[j]);
		}
		/*for(int i=0;i<=5*n;i++){
			cout<<xx[i]<<",";
		}
		cout<<endl;*/
		if(xx[su2/2]==0){
			cout<<0<<endl;
			return 0;
		}
	}


	while(true){
		llo su=0;
		for(llo i=0;i<n;i++){
			su+=it[i];
		}
		if(su%2==1){
			cout<<0<<endl;
			return 0;
		}
		llo ans=-1;
		for(llo i=0;i<n;i++){
			if(it[i]%2==1){
				ans=i;
			}
		}
		if(ans>=0){
			cout<<1<<endl;
			cout<<ans+1<<endl;
			return 0;
		}
		for(llo i=0;i<n;i++){
			it[i]/=2;
		}
	}






 
 
	return 0;
}