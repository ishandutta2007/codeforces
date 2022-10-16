#include<bits/stdc++.h>
#define int long long
const int N=505;
using namespace std;

int res[N][N];
void solve(){
	memset(res,0,sizeof(res));
	int n,k,r,c;cin>>n>>k>>r>>c;
	r%=k,c%=k;
	for(int i=0;i<k;i++){
		res[r][c]=1;
		r++;r%=k;
		c++;c%=k;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<(res[i%k][j%k]?'X':'.');
		}
		cout<<'\n';
	}
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}