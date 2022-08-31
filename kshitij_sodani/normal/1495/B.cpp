//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int n;
int it[1000003];
int co[1000003];
int co2[1000003];
int co3[1000003];

int co4[1000003];

int ma[1000003];
int ma2[1000003];
int ma3[1000003];
int ma4[1000003];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];

	}
	int ans=0;
	for(int i=1;i<=n;i++){
		co[i]=0;
		if(i>1){
			if(it[i-1]>it[i-2]){
				co[i]=co[i-1]+1;
			}
		}
	}
	for(int i=n;i>=1;i--){
		co2[i]=0;
		if(i<n){
			if(it[i-1]>it[i]){
				co2[i]=co2[i+1]+1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		co3[i]=0;
		if(i>1){
			if(it[i-1]<it[i-2]){
				co3[i]=co3[i-1]+1;
			}
		}
	}
	for(int i=n;i>=1;i--){
		co4[i]=0;
		if(i<n){
			if(it[i-1]<it[i]){
				co4[i]=co4[i+1]+1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ma[i]=max(ma[i-1],max(co3[i],co4[i]));
	}

	for(int i=n;i>=1;i--){
		ma2[i]=max(ma2[i+1],max(co3[i],co4[i]));
	}

	//cout<<co[4]<<","<<co2[4]<<endl;
	//set<int> cur;

	for(int i=1;i<n-1;i++){
		if(it[i]>it[i-1] and it[i]>it[i+1]){
			if(i+1+co2[i+1]<n){
				if(ma2[i+1+co[i+1]+1]>=max(co[i+1],co2[i+1])){
					continue;
				}
			}
			if(i+1-co[i+1]>1){
				if(ma[i+1-co[i+1]-1]>=max(co[i+1],co2[i+1])){
					continue;
				}
			}
			int x=co[i+1];
			int y=co2[i+1];

			if(y>((x-(1-(x%2))))){
				if(x>((y-(1-(y%2))))){
					if(co3[i+1-co[i+1]]>=max(co[i+1],co2[i+1])){

						continue;
					}
					if(co4[i+1+co2[i+1]]>=max(co[i+1],co2[i+1])){
						
						continue;
					}
					ans+=1;
					continue;
				}
			}



			
		}
	}
	
	cout<<ans<<endl;






 
	return 0;
}