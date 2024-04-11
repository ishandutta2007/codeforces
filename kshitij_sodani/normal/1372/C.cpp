//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int t;
int it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		//int ans=0;
		int st=0;
		for(int i=0;i<n;i++){
			cin>>it[i];
			/*if(it[i]==i+1){
				st=0;
			}
			else{
				if(st==0){
					st=1;
					ans++;
				}
			}*/
		}
		int ind=0;
		for(int i=0;i<n;i++){
			if(it[i]==i+1){
				ind++;
			}
			else{
				break;
			}
		}
		int ind2=n-1;
		for(int i=n-1;i>=0;i--){
			if(it[i]==i+1){
				ind2--;
			}
			else{
				break;
			}
		}
		//cout<<ind<<":"<<ind2<<endl;
		if(ind==n){
			cout<<0<<endl;
			continue;
		}
		int ans=1;
		for(int i=ind;i<=ind2;i++){
			if(it[i]==i+1){
				ans++;
				break;
			}
		}
		cout<<ans<<endl;
	}	




 
	return 0;
}