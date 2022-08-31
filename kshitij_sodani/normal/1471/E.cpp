//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int ask(int i){
	cout<<"? "<<i+1<<endl;
	int x;
	cin>>x;
	return x;
}
int n,k;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;

	for(int i=0;i<400;i++){
		ask(0);
	}
	for(int i=0;i<n;i+=max(n/300,1)){
		int x=ask(i);
		if(x>k){
			int ind=i;
			int cur=x;
			for(int j=19;j>=0;j--){
				if((1LL<<j)>=n){
					continue;
				}
				int cur2=ask((ind-(1<<j)+n)%n);
				if(cur2>=cur){
					cur2=cur;
					ind=(ind-(1<<j)+n)%n;
				}
			}
			cout<<"! "<<((ind-1+n)%n)+1<<endl;
			return 0;
			/*vector<int> ss;
			for(int j=-300;j<300;j++){
				ss.pb((i+j+n*300)%n);
			}*/

			//for(auto j:ss){
				
				/*if(aa==1){
					continue;
				}*/
				/*while(aa==1){
					aa=ask(j);
				}*/
				/*if(aa==1){
					aa=ask(j);
				}*/
			/*	int aa=ask((j+2)%n);
				int bb=ask((j+1)%n);
				if(bb==(aa/2)){
					cout<<"! "<<j+1<<endl;
					return 0;
				}
			}*/
			/*if(x==1){
				x=ask(i);
			}
			int y=ask(i);*/
		}
		
	}







 
	return 0;
}