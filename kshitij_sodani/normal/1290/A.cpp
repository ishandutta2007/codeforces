#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef  long long int llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m,k;
		cin>>n>>m>>k;
		llo it[n];
		k=min(m-1,k);
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		llo mi=0;
		if(k==0 and m==1){
			cout<<max(it[0],it[n-1])<<endl;
			continue;
		}

		for(llo i=0;i<k+1;i++){
			llo ma=1000000000000;
			if(m-k-1==0){
				mi=max(mi,max(it[i],it[n-(k-i)-1]));
				continue;
			}
			for(llo j=0;j<m-k;j++){
				ma=min(ma,max(it[i+j],it[n-(k-i)-(m-k-1-j)-1]));
				
			}
			
			mi=max(mi,ma);

		}
		
		cout<<mi<<endl;
	}
















	return 0;
}