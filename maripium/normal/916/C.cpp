#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
//#define fi first
//#define se second
using namespace std;
const int mst=1e5+3,inf=1e9;
int n,m;
signed main(){
	cin>>n>>m;
	if(n==2){cout<<mst<<' '<<mst<<'\n'<<1<<' '<<2<<' '<<mst;exit(0);}
	cout<<3<<' '<<mst<<endl;
	for(int i=2;i<=n;i++){
		if(i==n)cout<<1<<' '<<i<<' '<<3<<endl;
		else if(i==2)cout<<1<<' '<<i<<' '<<mst-n<<endl;
		else cout<<1<<' '<<i<<' '<<1<<endl;
		}
	m-=(n-1);
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(m==0)return 0;
			cout<<i<<' '<<j<<' '<<inf-1<<endl;
			m--;
			//if(m==0)return 0;
			}
		}
}