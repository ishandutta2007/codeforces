//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int it[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;

		for(int i=0;i<n;i++){
			cin>>it[i];
		}
		int ind=0;
		while(k>0){
			while(ind<n){
				if(it[ind]==0){
					ind++;
				}
				else{
					break;
				}
			}
			if(ind==n){
				break;
			}
			k--;
			it[ind]-=1;
			it[n-1]+=1;
		}
		for(int i=0;i<n;i++){
			cout<<it[i]<<" ";
		}
		cout<<endl;
	}





 
 
	return 0;
}