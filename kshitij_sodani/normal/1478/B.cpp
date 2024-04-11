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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,d;
		cin>>n>>d;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(it[i]<d){
				cout<<"NO"<<endl;
			}
			else if((it[i]%d)==0){
				cout<<"YES"<<endl;
			}
			else if(it[i]>=d*10){
				cout<<"YES"<<endl;
			}
			else{
				llo st=0;
				for(llo j=0;j<10;j++){
					if((10*j)+d<=it[i]){
						if((it[i]-10*j)%d==0){
							st=1;
						}
					}
				}
				if(st){
					cout<<"YES"<<endl;
				}
				else{
					cout<<"NO"<<endl;
				}
			}
		}

	}







 
	return 0;
}