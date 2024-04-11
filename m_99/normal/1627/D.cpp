#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001
long long cnt[1000001];
long long sum[1000001];
int main(){
	
	int n;
	cin>>n;
	
	rep(_,n){
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	int ans = 0;
	for(int i=1000000;i>=1;i--){
		long long S = 0;
		for(int j=i;j<=1000000;j+=i){
			S += cnt[j];
		}
		sum[i] = S * (S-1) / 2;
		for(int j=i*2;j<=1000000;j+=i){
			sum[i] -= sum[j];
		}
		if(cnt[i]==0){
			if(sum[i]>0){
				cnt[i]++;
				sum[i] += S;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}