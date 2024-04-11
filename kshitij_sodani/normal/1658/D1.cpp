#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int it[(1<<17)+10];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int l,r;;
		cin>>l>>r;
		for(int i=0;i<r-l+1;i++){
			cin>>it[i];
		}
		int n=r-l+1;
		int ans=0;
		for(int j=0;j<17;j++){
			int su=0;
			for(int i=0;i<n;i++){
				if((1<<j)&it[i]){
					su++;
				}
			}
			if(su+su>n){
				ans+=(1<<j);
			}
		}
		cout<<ans<<endl;
	}








	return 0;
}