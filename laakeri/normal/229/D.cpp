#include <bits/stdc++.h>
using namespace std;

int x[101010];
int m[101010];
int dp[101010];
int dps[101010];

int st[101010];

int sum(int a, int b){
	if (b<a) return 0;
	if (a==0) return st[b];
	return st[b]-st[a-1];
}

int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x[i];
	}
	for (int i=0;i<=n;i++){
		st[i]=x[i];
		if (i) st[i]+=st[i-1];
	}
	int v=0;
	int mm=0;
	for (int i=1;i<=n;i++){
		mm=max(mm, m[i]);
		dps[i]=sum(mm+1, i);
		dp[i]=dp[mm]+1;
		v=max(v, dp[i]);
		//cout<<i<<" "<<mm<<" "<<dp[i]<<" "<<dps[i]<<endl;
		int mi=i;
		int ma=n;
		while (mi<=ma){
			int mid=(mi+ma)/2;
			if (sum(i+1, mid)>=dps[i]){
				m[mid]=max(m[mid], i);
				ma=mid-1;
			}
			else{
				mi=mid+1;
			}
		}
	}
	cout<<n-v<<endl;
}