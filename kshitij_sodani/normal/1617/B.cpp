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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%2==0){
			int x=(n-1)/2;
			cout<<x+1<<" "<<x<<" "<<1<<endl;
		}
		else{
			int x=(n-1)/2;
			if((x-1)%2==1){
				cout<<x-1<<" "<<x+1<<" "<<1<<endl;
			}
			else{
				cout<<x-2<<" "<<x+2<<" "<<1<<endl;
			}
		}

	}





 
	return 0;
}