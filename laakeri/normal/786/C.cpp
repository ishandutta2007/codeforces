#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int a[101010];

int n;

int dp[101010];

int cnt[101010];

int cac[101010];

int squads(int k){
	if (cac[k]) return cac[k];
	for (int i=0;i<=n;i++){
		cnt[i]=0;
		dp[i]=0;
	}
	int i2=0;
	int c=0;
	for (int i=0;i<n;i++){
		if (cnt[a[i]]==0){
			c++;
		}
		cnt[a[i]]++;
		while (c>k){
			if (cnt[a[i2]]==1){
				c--;
			}
			cnt[a[i2]]--;
			i2++;
		}
		if (i2==0){
			dp[i]=1;
		}
		else{
			dp[i]=1+dp[i2-1];
		}
	}
	cac[k]=dp[n-1];
	return dp[n-1];
}

int ans[101010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
// 	n=100000;
	for (int i=0;i<n;i++){
		cin>>a[i];
// 		a[i]=i+1;
	}
	int S=1;
	while (S*S<=n){
		S++;
	}
	S=min(S, n);
	for (int i=1;i<=S;i++){
		ans[i]=squads(i);
	}
	int ub=ans[S];
	for (int i=1;i<=ub;i++){
		int mi=1;
		int ma;
		if (i==1){
			ma=n;
		}
		else{
			ma=min(n, n/(i-1)+1);
		}
// 		cout<<i<<" mm "<<mi<<" "<<ma<<endl;
		while (mi<=ma){
			int mid=(mi+ma)/2;
			int s=squads(mid);
// 			cout<<mid<<" "<<s<<endl;
			if (s>=i){
// 				cout<<i<<" "<<s<<" "<<mid<<endl;
				ans[mid]=s;
				mi=mid+1;
			}
			else{
				ma=mid-1;
			}
		}
	}
	ans[n]=1;
	for (int i=n-1;i>=1;i--){
		ans[i]=max(ans[i+1], ans[i]);
	}
	for (int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}