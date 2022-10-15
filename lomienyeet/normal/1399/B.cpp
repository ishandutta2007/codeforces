#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define yy "YES\n"
#define nn "NO\n"
void solve(){
	int N;
	cin>>N;
	int a[N],b[N];
	ll ans=0;
	cin>>a[0];
	int mini=a[0],mini2=0;
	for(int i=1;i<N;i++){
		cin>>a[i];
		if(a[i]<mini)mini=a[i];
	}
	cin>>b[0];
	mini2=b[0];
	for(int i=1;i<N;i++){
		cin>>b[i];
		if(b[i]<mini2)mini2=b[i];
	}
	for(int i=0;i<N;i++){
		ans+=max(a[i]-mini,b[i]-mini2);
	}
	cout<<ans<<"\n";
}
int main(){
    int T=1;
	cin>>T;
    while(T--){
        solve();
    }
    return 0;
}