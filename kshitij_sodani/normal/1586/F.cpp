//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	int xx=1;
	int ans=0;
	while(xx<n){
		xx*=k;
		ans++;
	}
	cout<<ans<<endl;
	ans++;
	for(int j=1;j<=n;j++){
		for(int i=j+1;i<=n;i++){
			int x=i-1;
			int y=j-1;
			int co=0;
			int zz=k;
			vector<int> xx;
			while(xx.size()<ans){
				xx.pb(x%k);
				x/=k;
			}
			vector<int> yy;
			while(yy.size()<ans){
				yy.pb(y%k);
				y/=k;
			}
			int ans2=0;

			while(true){
				//ans++;
				if(xx.back()!=yy.back()){
					break;
				}
				xx.pop_back();
				yy.pop_back();
				ans2++;
			}
			cout<<ans2<<" ";
			

			/*while(true){
				co++;
				if((x/zz)!=(y/zz)){
					cout<<co<<" ";
					break;
				}
				zz*=k;
				//x/=k;
				//y/=k;
			}*/

		}
	}
	cout<<endl;
 
 
 

 
	return 0;
}