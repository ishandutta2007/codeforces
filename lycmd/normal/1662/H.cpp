#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m;
vector<int>ans;
int _check(int x){
    int d=n%x,k=m-1+d;
    if(d>1)return 0;
    d=k%x;
    if(d>1)return 0;
    k=n-1+d,d=k%x;
    if(d>1)return 0;
    k=m-2+d,d=k%x;
    return !d;
}
int check(int x){
    int flg=_check(x);
    swap(n,m);
    flg|=_check(x);
    swap(n,m);
    return flg;
}
void solve(int n){
	for(int i=1;i*i<=n;i++)
		if(n%i==0){
			if(check(i))
				ans.push_back(i);
			if(check(n/i))
				ans.push_back(n/i);
		}
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m,ans.clear();
		solve(n-2),solve(n-1),solve(n);
		solve(m-2),solve(m-1),solve(m);
		sort(ans.begin(),ans.end());
		ans.erase(unique(ans.begin(),ans.end()),ans.end());
		cout<<ans.size()<<" ";
		for(int x:ans)
			cout<<x<<" ";
		cout<<"\n";
	}
}