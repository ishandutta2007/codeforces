#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int x=(i/2+j/2)%2;
				if((i+j)%2==1){
					x^=1;
				}
				cout<<x<<" ";
			}
			cout<<endl;
		}
	}





	return 0;
}