#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,a[N],s[N];
map<int,int>cnt;
int solve(int x){
	if(cnt[x]){
		cnt[x]--;
		return 1;
	}
	return x==1?0:solve(x/2)&&solve((x+1)/2);
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n,cnt.clear();
		int s=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],s+=a[i],cnt[a[i]]++;
		cout<<(solve(s)?"YES\n":"NO\n");
	}
	return 0;
}