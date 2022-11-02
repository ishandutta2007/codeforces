#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll dp[66][2];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll s,x;
	cin>>s>>x;
	dp[0][0]=1;
	for (ll i=0;i<60;i++){
		for (int c=0;c<2;c++){
			if (dp[i][c]){
				//cout<<i<<" "<<c<<" "<<dp[i][c]<<endl;
				for (int t1=0;t1<2;t1++){
					for (int t2=0;t2<2;t2++){
						int su=c+t1+t2;
						int xo=t1^t2;
						if (xo==0&&(x&(1ll<<i))>0) continue;
						if (xo==1&&(x&(1ll<<i))==0) continue;
						if (su%2==0&&(s&(1ll<<i))>0) continue;
						if (su%2==1&&(s&(1ll<<i))==0) continue;
						dp[i+1][su/2]+=dp[i][c];
					}
				}
			}
		}
	}
	ll v=0;
	for (ll i=0;;i++){
		if ((1ll<<i)>s){
			if ((1ll<<i)<=x){
				cout<<0<<endl;
				return 0;
			}
			v=dp[i][0];
			break;
		}
	}
	if (x==s){
		v-=2ll;
	}
	cout<<v<<endl;
}