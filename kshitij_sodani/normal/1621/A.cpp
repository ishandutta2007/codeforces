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
	
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(k>((n+1)/2)){
			cout<<-1<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j){
					if(i%2==0){
						if((i/2)+1<=k){
							cout<<"R";
							continue;
						}
					}
				}
				cout<<".";
			}
			cout<<endl;
		}


	}





 
	return 0;
}