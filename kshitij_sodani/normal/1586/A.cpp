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
		int su=0;
		int ind=-1;
		for(int i=0;i<n;i++){
			cin>>it[i];
			su+=it[i];
			if(it[i]%2==1){
				ind=i;
			}
		}
		int st=0;
		for(int j=2;j*j<=su;j++){
			if(su%j==0){
				st=1;
			}
		}
		if(st==1){
			cout<<n<<endl;
			for(int i=0;i<n;i++){
				cout<<i+1<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<n-1<<endl;
			for(int i=0;i<n;i++){
				if(i==ind){
					continue;
				}
				cout<<i+1<<" ";
			}
			cout<<endl;
		}

	}
 
 
 

 
	return 0;
}