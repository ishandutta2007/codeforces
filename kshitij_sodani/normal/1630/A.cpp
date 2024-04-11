//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
/*	nn=2;

	brute(0);
	nn=3;
	brute(0);*/


	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		
		if(n==4 and k==3){
			cout<<-1<<endl;
			continue;
		}
		for(int i=0;i<(n/2);i++){
			if(k==0){

			}
			else if(k==n-1){
				if(i==0){
					cout<<0<<" "<<2<<endl;
					continue;
				}
				if(i==1){
					cout<<n-3<<" "<<1<<endl;
					continue;
				}

				if(i==2){
					cout<<n-1<<" "<<n-2<<endl;
					continue;
				}


			}
			else{
				if(i==0){
					cout<<n-1-k<<" "<<i<<endl;
					continue;
				}
				if(i==k or i==n-1-k){
					cout<<k<<" "<<n-1<<endl;
					continue;
				}
			}
			cout<<i<<" "<<n-i-1<<endl;
		}





	}




 
	return 0;
}