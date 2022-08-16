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
		llo n;
		cin>>n;
		for(llo i=0;i<2*n;i++){
			cin>>it[i];
		}
		sort(it,it+2*n);
		llo st=1;
		for(llo i=0;i<2*n;i+=2){
			if(it[i]!=it[i+1]){
				st=0;
			}
			//cout<<it[i]<<",";
		}
		//cout<<endl;
		if(st){
			llo su=0;
			llo su2=0;
			vector<llo> kk;
			for(llo i=2;i<2*n;i+=2){
				if((it[i]-it[i-2])%(i)){
					st=0;
				}
				else if(it[i]-it[i-2]==0){
					st=0;
				}
				else{
					kk.pb((it[i]-it[i-1])/i);
					su+=su2+(it[i]-it[i-1])/i;
					su2+=(it[i]-it[i-1])/i;
				//	cout<<su2<<":"<<endl;
					//cout<<su<<",,";
				//	su+=2*((it[i]-it[i-2])/2);
				}
			}
			//cout<<endl;
			//cout<<su<<":"<<endl;
			if(it[0]<=2*su){
				st=0;
			}
			else if(((it[0]-2*su)%(2*n))!=0){
			//	cout<<it[0]<<":"<<su<<endl;
				st=0;
			}
			/*if(it[0]<su){
				st=0;
			}
			else if((it[0]-su)%2==1){
				st=0;
			}*/

			//if()
		}
		if(st==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}







 
	return 0;
}