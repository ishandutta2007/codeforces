//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

 	llo t;
 	cin>>t;
 	while(t--){
 		string s;
 		cin>>s;
 		for(llo i=0;i<10;i++){
 			it[i]=s[i]-'0';
 		}
 	//	cout<<it[1]<<":"<<endl;
 		llo ans=10;
 		for(llo i=0;i<(1<<10);i++){
 			llo st=1;
 			llo mi=10;
 			for(llo j=0;j<10;j++){

 				if(s[j]=='1'){
 					if((1<<j)&i){
 					}
 					else{
 						st=0;
 						break;
 					}
 				}
 				else if(s[j]=='0'){
 					if((1<<j)&i){
 						st=0;
 						break;
 					}
 				}
 			}
 			if(st==0){
 				continue;
 			}
 			/*if(it[0]<=1){
 				cout<<i<<":"<<endl;
 			}*/
 			llo su=0;
 			llo su2=0;
 			llo le=5;
 			llo le2=5;
 			for(llo j=0;j<10;j++){
 				if((1<<j)&i){
 					if(j%2==0){
 						su+=1;
 					}
 					else{
 						su2+=1;
 					}
 				}
 				if(j%2==0){
 						le--;
 					}
 					else{
 						le2--;
 					}
 				if(su+le<su2){
 					mi=j+1;
 					break;
 				}
 				if(su2+le2<su){
 					mi=j+1;
 					break;
 				}
 			}
 			ans=min(ans,mi);


 		}
 		cout<<ans<<endl;
 	}
 

 
 
 
	return 0;
}