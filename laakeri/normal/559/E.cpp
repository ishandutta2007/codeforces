#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

pair<int, int> a[111];

int can[333][333];

set<int> ccs;
map<int, int> ccm;

vector<int> lol;

ll used[111];

ll git=1;

int n;

int t[111];

int dp2[333];

const int inf=1e9;

int ck(int l, int r){
	for (int i=0;i<333;i++){
		dp2[i]=-inf;
	}
	int la=-1;
	int ra=-1;
	for (int i=0;i<n;i++){
		if (a[i].F>=l&&a[i].F<=r){
			ra=i;
			if (la==-1) la=i;
		}
	}
	if (la==-1) return 0;
	dp2[la]=l;
	for (int i=la;i<=ra;i++){
		int ma=0;
		for (int ii=i;ii<=ra;ii++){
			if (a[ii].F<=dp2[i]){
				dp2[ii+1]=max(dp2[ii+1], a[ii].F+a[ii].S);
			}
			if (a[ii].F-a[ii].S<=dp2[i]){
				dp2[ii+1]=max(dp2[ii+1], max(a[ii].F, ma));
			}
			ma=max(ma, a[ii].F+a[ii].S);
		}
	}
	for (int i=la;i<=ra+1;i++){
		if (dp2[i]>=r){
			return 1;
		}
	}
	return 0;
}

int dp[333];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i].F>>a[i].S;
		ccs.insert(a[i].F-a[i].S);
		ccs.insert(a[i].F);
		ccs.insert(a[i].F+a[i].S);
	}
	sort(a, a+n);
	int i2=0;
	for (int cc:ccs){
		lol.push_back(cc);
		ccm[cc]=i2++;
	}
	for (int i=0;i<(int)lol.size();i++){
		for (int ii=i+1;ii<(int)lol.size();ii++){
			can[i][ii]=ck(lol[i], lol[ii]);
			if (can[i][ii]){
				//cout<<lol[i]<<" a "<<lol[ii]<<endl;
			}
		}
	}
	int mv=0;
	for (int i=0;i<(int)lol.size();i++){
		for (int ii=i+1;ii<(int)lol.size();ii++){
			if (can[i][ii]){
				mv=max(mv, dp[i]+(lol[ii]-lol[i]));
				for (int iii=ii+1;iii<(int)lol.size();iii++){
					dp[iii]=max(dp[iii], dp[i]+(lol[ii]-lol[i]));
				}
			}
		}
	}
	cout<<mv<<endl;
}