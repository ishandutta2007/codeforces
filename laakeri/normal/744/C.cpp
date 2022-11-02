#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[1<<16][222];

char c[22];
int r[22];
int bl[22];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int tor=0;
	int tob=0;
	for (int i=0;i<n;i++){
		cin>>c[i]>>r[i]>>bl[i];
		tor+=r[i];
		tob+=bl[i];
	}
	for (int b=0;b<(1<<n);b++){
		for (int rd=0;rd<200;rd++){
			dp[b][rd]=-1;
		}
	}
	dp[0][0]=0;
	for (int b=0;b<(1<<n);b++){
		for (int rd=0;rd<160;rd++){
			if (dp[b][rd]==-1) continue;
			int hr=0;
			int hb=0;
			for (int i=0;i<n;i++){
				if (b&(1<<i)){
					if (c[i]=='R') hr++;
					else hb++;
				}
			}
			for (int i=0;i<n;i++){
				if ((b&(1<<i))==0){
					int rp=max(r[i]-hr, 0);
					int bp=max(bl[i]-hb, 0);
					int nrd=rd+r[i]-rp;
					int nbd=dp[b][rd]+bl[i]-bp;
					dp[b|(1<<i)][nrd]=max(dp[b|(1<<i)][nrd], nbd);
				}
			}
		}
	}
	int v=max(tor, tob);
	for (int i=0;i<160;i++){
		if (dp[(1<<n)-1][i]>=0){
			int tv=max(tor-i, tob-dp[(1<<n)-1][i]);
			v=min(v, tv);
		}
	}
	cout<<v+n<<endl;
}