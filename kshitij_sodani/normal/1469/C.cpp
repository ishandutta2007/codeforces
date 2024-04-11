//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[200001];
llo aa[200001];
pair<llo,llo> ac[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		llo st=1;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			aa[i]=it[i];
			if(i>0){
				ac[i]={it[i],it[i]+k-1};
				if(i==n-1){
					ac[i].b=it[i];
				}
				ac[i].a=max(ac[i].a,ac[i-1].a-k+1);
				ac[i].b=min(ac[i].b,ac[i-1].b+k-1);
			}
			else{
				ac[i]={it[i],it[i]};
			}
			if(ac[i].a>ac[i].b){
				st=0;
			}
			/*if(i==n-1){
				if(it[i]<ac[i].a or it[i]>ac[i].b){
					st=0;
				}
			}*/
		}
		/*for(llo i=0;i<n-2;i++){
			if(it[i]>=it[i+1]+k){
				if(abs(it[i]-k+1-it[i+2])>=k-1+k){
					st=0;
				}
			}
		}
		for(llo i=0;i<n/2;i++){
			swap(it[i],it[n-i-1]);

		}
		for(llo i=0;i<n-2;i++){
			if(it[i]>=it[i+1]+k){
				if(abs(it[i]-k+1-it[i+2])>=k-1+k){
					st=0;
				}
			}
		}*/
		if(st){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}


	}





	return 0;
}