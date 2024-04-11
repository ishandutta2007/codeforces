//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int n;
int t;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%2==0){
			for(int i=1;i<=n;i+=2){
				cout<<i+1<<" "<<i<<" ";
			}
			cout<<endl;

		}
		else{
			cout<<"3 1 2 ";
			for(int i=4;i<=n;i+=2){
				cout<<i+1<<" "<<i<<" ";
			}
			cout<<endl;
		}
	}









	return 0;
}