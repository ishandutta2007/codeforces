#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[N],mx,ans;map<int,int> cnt;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),cnt.clear(),mx=0,ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
		for(auto i:cnt)if(i.second>mx)mx=i.second;
		ans=n-mx;
		while(mx<n)mx<<=1,ans++;
		printf("%d\n",ans);
	}
	return 0;
}