#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a,b;
};
bool cmp(node a,node b){
	if(a.a!=b.a){
		return a.a<b.a;
	}
	return a.b>b.b;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		node t[n+1];
		for(int i=1;i<=n;i++){
			cin>>t[i].a>>t[i].b;
		}
		sort(t+1,t+n+1,cmp);
		int ll=1,lr=n,ok=0;
		for(int i=1;i<=n;i++){
			if(ok){
				if(ll==t[i].a){
					cout<<ll<<" "<<lr<<" "<<t[i].b+1<<endl; 
				}
				else{
					cout<<ll<<" "<<lr<<" "<<t[i].a-1<<endl;
				}
			}
			ll=t[i].a,lr=t[i].b;
			ok=1;
			if(ll==lr){
				cout<<ll<<" "<<lr<<" "<<ll<<endl;
				ok=0;
			}
		}
		cout<<endl;
	} 
}