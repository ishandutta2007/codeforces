#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[101];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int mid=((1ll<<m)-n-1)/2;
		for(int x=1;x<=n;x++){
			string str;
			cin>>str;
			a[x]=bitset<65>(str).to_ullong();
		}
		sort(a+1,a+n+1);
		for(int x=1;x<=n;x++)
		if(a[x]<=mid)mid++;
		cout<<bitset<65>(mid).to_string().substr(65-m)<<endl;
	}
}