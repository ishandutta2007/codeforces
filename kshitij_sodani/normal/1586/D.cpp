//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int ans[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int co=0;
	vector<int> ind;
	ans[n-1]=1;
	for(int i=2;i<=n;i++){
		cout<<"? ";
		for(int j=0;j<n;j++){
			if(j<n-1){
				cout<<i<<" ";
			}
			else{
				cout<<1<<" ";
			}
		}
		cout<<endl;
		int x;
		cin>>x;
		if(x!=0){
			co++;
			x--;
			ans[x]=(ans[n-1]-(i-1));
		}
		else{

		}
	}
	for(int i=2;i<=n;i++){
		cout<<"? ";
		for(int j=0;j<n;j++){
			if(j<n-1){
				cout<<1<<" ";
			}
			else{
				cout<<i<<" ";
			}
		}
		cout<<endl;
		int x;
		cin>>x;
		if(x!=0){
			co++;
			x--;
			ans[x]=(ans[n-1]+(i-1));
		}
		else{

		}
	}
	int mi=1;;
	for(int i=0;i<n;i++){
		mi=min(mi,ans[i]);
	}
	for(int i=0;i<n;i++){
		ans[i]+=(1-mi);
	}
	cout<<"! ";
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;


 
 
 

 
	return 0;
}