//plase fix weird order of queue
//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
 
llo t;

int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
 
 	int ans=0;
 	for(int i=-n;i<=n;i++){
 		for(int j=-n;j<=n;j++){
 			if(max(max(abs(i),abs(j))-min(abs(i),abs(j))-1,0)+abs(i)+abs(j)>n){
 				continue;
 			}
 			//llo le=n-max(max(abs(i),abs(j))-min(abs(i),abs(j))-1,0)+abs(i)+abs(j);
 			llo le=n-abs(i)-abs(j);
 			//
 		/*	if(le<0){
 			//	ans++;
 				continue;
 			}*/

 			if(le%2){

 				continue;
 			}
 			if(le==max(abs(i),abs(j))-min(abs(i),abs(j))-1){
 				//cout<<i<<":"<<j<<endl;
 				ans++;
 				continue;
 			}	
 			if(le==max(abs(i),abs(j))-min(abs(i),abs(j))){
 				ans++;
 				continue;
 			}
 			if(le==max(abs(i),abs(j))-min(abs(i),abs(j))+1){
 				ans++;
 				continue;
 			}
 			le-=(max(abs(i),abs(j))-min(abs(i),abs(j)));
 			if((max(abs(i),abs(j))-min(abs(i),abs(j)))%2==1){


 				le--;
 				if(le%4==2){
 					ans++;
 					continue;
 				}
 			}
 			/*if(le<0){
 				continue;
 			}*/
 			if(le%4){
 				continue;
 			}

 			/*if((n-abs(i)-abs(j))%4){
 				continue;
 			}*/
 			//cout<<i<<":"<<j<<endl;
 			ans++;
 		}
 	}
 	cout<<ans<<endl;
 
 
 
	return 0;
}