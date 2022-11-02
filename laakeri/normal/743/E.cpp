#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int n;
int a[1010];
vector<int> pos[10];
int pp[1010];

int dp[1010][9];

const int k=8;

int solve0(vector<int> perm, int take) {
	if (take==0) return 1;
	int tt=0;
	int j=0;
	for (int i=1;i<=n;i++){
		if (a[i]==perm[j]) tt++;
		if (tt==take){
			tt=0;
			j++;
			if (j==k) return 1;
		}
	}
	return 0;
}

int solve(vector<int> perm, int take){
	memset(dp, -1, sizeof(dp));
	dp[1][0]=0;
	int v=-1;
	for (int i=1;i<=n;i++){
		v=max(v, dp[i][k]);
		for (int j=0;j<k;j++){
			if (dp[i][j]==-1) continue;
			dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
			if (a[i]==perm[j]){
				int po1=pp[i]+take-1;
				int po2=pp[i]+take;
				if (take>0&&po1<(int)pos[a[i]].size()){
					dp[pos[a[i]][po1]+1][j+1]=max(dp[pos[a[i]][po1]+1][j+1], dp[i][j]+take);
				}
				if (po2<(int)pos[a[i]].size()){
					dp[pos[a[i]][po2]+1][j+1]=max(dp[pos[a[i]][po2]+1][j+1], dp[i][j]+take+1);
				}
			}
			if (take==0){
				dp[i][j+1]=max(dp[i][j], dp[i][j+1]);
			}
		}
	}
	v=max(v, dp[n+1][k]);
	return v;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		pp[i]=pos[a[i]].size();
		pos[a[i]].push_back(i);
	}
	vector<int> perm;
	for (int i=1;i<=k;i++){
		perm.push_back(i);
	}
	int v=0;
	while (1){
		int mi=0;
		int ma=n/k+3;
		int f=0;
		while (mi<=ma){
			int mid=(mi+ma)/2;
			int tv=solve0(perm, mid);
			if (tv){
				f=mid;
				mi=mid+1;
			}
			else{
				ma=mid-1;
			}
		}
		v=max(v, solve(perm, f));
		if (!next_permutation(perm.begin(), perm.end())) break;
	}
	cout<<v<<endl;
}