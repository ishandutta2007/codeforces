#include <bits/stdc++.h>
using namespace std;
void solve(){
	vector<int> a;
	int N;
	cin>>N;
	a.resize(N);
	for(int i=0;i<N;i++)cin>>a[i];
	int ans=N+5;
	vector<int> e(N+1,-1);
	for(int i=0;i<N;i++){
		if(e[a[i]]!=-1){
			ans=min(ans,i-e[a[i]]+1);
		}
		e[a[i]]=i;
	} 
	if(ans>N)cout<<"-1\n";
	else cout<<ans<<"\n";
}
int main(){
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}