#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
string s;

int pos(int i, int uv, int uk, int ux){
	for (int j=0;j<i;j++){
		if (s[j]=='V') uv--;
		if (s[j]=='K') uk--;
		if (s[j]=='X') ux--;
	}
	if (uv<0) uv=0;
	if (uk<0) uk=0;
	if (ux<0) ux=0;
	return i+uv+uk+ux;
}

int dp[77][77][77][2];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>s;
	int tv=0;
	int tk=0;
	int tx=0;
	for (int i=0;i<n;i++){
		if (s[i]!='V'&&s[i]!='K') s[i]='X';
		if (s[i]=='V') tv++;
		if (s[i]=='K') tk++;
		if (s[i]=='X') tx++;
	}
	assert(tv+tk+tx==n);
	for (int i=0;i<=n;i++){
		for (int ii=0;ii<=n;ii++){
			for (int iii=0;iii<=n;iii++){
				dp[i][ii][iii][0]=n*n;
				dp[i][ii][iii][1]=n*n;
			}
		}
	}
	dp[0][0][0][0]=0;
	for (int i=0;i<=tv;i++){
	for (int ii=0;ii<=tk;ii++){
	for (int iii=0;iii<=tx;iii++){
	for (int k=0;k<2;k++){
		int p=i+ii+iii;
		if (p==n) continue;
		int va=dp[i][ii][iii][k];
// 		cout<<i<<" "<<ii<<" "<<iii<<" "<<k<<" "<<dp[i][ii][iii][k]<<endl;
		if (i<tv){
			int c=0;
			int f=0;
			for (int j=0;j<n;j++){
				if (s[j]=='V'){
					c++;
					if (c==i+1){
						f=j;
						break;
					}
				}
			}
			int vp=pos(f, i, ii, iii);
			assert(vp>=p);
			dp[i+1][ii][iii][1]=min(dp[i+1][ii][iii][1], va+vp-p);
		}
		if (ii<tk&&k==0){
			int c=0;
			int f=0;
			for (int j=0;j<n;j++){
				if (s[j]=='K'){
					c++;
					if (c==ii+1){
						f=j;
						break;
					}
				}
			}
			int vp=pos(f, i, ii, iii);
			assert(vp>=p);
// 			cout<<"v "<<vp<<" "<<p<<endl;
			dp[i][ii+1][iii][0]=min(dp[i][ii+1][iii][0], va+vp-p);
		}
		if (iii<tx){
			int c=0;
			int f=0;
			for (int j=0;j<n;j++){
				if (s[j]=='X'){
					c++;
					if (c==iii+1){
						f=j;
						break;
					}
				}
			}
			int vp=pos(f, i, ii, iii);
			assert(vp>=p);
			dp[i][ii][iii+1][0]=min(dp[i][ii][iii+1][0], va+vp-p);
		}
	}
	}
	}
	}
	cout<<min(dp[tv][tk][tx][0], dp[tv][tk][tx][1])<<endl;
}