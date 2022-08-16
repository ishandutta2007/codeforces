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
		int n;
		cin>>n;
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>it[i];
			int st=1;
			for(int j=1;j<=100;j++){
				if(j*j==it[i]){
					st=0;
					break;
				}
			}
			ans+=st;
		}
		if(ans>0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}




 
 
	return 0;
}