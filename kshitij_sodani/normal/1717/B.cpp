#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,k,r,c;
		cin>>n>>k>>r>>c;
		r--;
		c--;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int x=i%k;
				int y=j%k;
				if((i+j)%k==(r+c)%k){
					cout<<"X";
				}
				else{
					cout<<".";
				}
			}
			cout<<endl;
		}
	}






	return 0;
}