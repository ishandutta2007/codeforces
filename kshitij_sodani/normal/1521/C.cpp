//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

int it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i+=2){
			int aa=i;
			int bb=i+1;
			if(bb==n){
				bb=0;
			}
			cout<<"? 2 "<<aa+1<<" "<<bb+1<<" "<<1<<endl;
			int x;
			cin>>x;
			if(x!=2){

			}
			else{
				cout<<"? 2 "<<bb+1<<" "<<aa+1<<" "<<1<<endl;
				cin>>x;
			}
			cout<<"? 1 "<<aa+1<<" "<<bb+1<<" "<<n-1<<endl;
			int y;
			cin>>y;
			if(y!=n-1){

			}
			else{
				cout<<"? 1 "<<bb+1<<" "<<aa+1<<" "<<n-1<<endl;
				cin>>y;
			}
			cout<<"? 1 "<<aa+1<<" "<<bb+1<<" "<<x<<endl;
			int z;
			cin>>z;
			if(z==x+1){
				it[aa]=x;
				it[bb]=y;
			}
			else{
				it[bb]=x;
				it[aa]=y;
			}



		}
		cout<<"! ";
		for(int i=0;i<n;i++){
			cout<<it[i]<<" ";
		}
		cout<<endl;



	}







	return 0;
}