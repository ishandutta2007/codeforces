//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>it[i];
		}
		int st=n;
		for(int i=n-1;i>=0;i--){
			if(it[i]==i+1){
				st--;
			}
			else{
				break;
			}
		}
		llo vis=0;
		long double ans=1;
		for(int i=0;i<m;i++){
			int aa;
			long double bb;
			cin>>aa>>bb;
			if(aa>=st){
				vis=1;
				ans=(ans*(1-bb));
			}
		}
		if(st==0){
			cout<<1<<endl;
			continue;
		}
		if(vis==0){
			cout<<0<<endl;
			continue;
		}
		cout<<setprecision(10)<<1-ans<<endl;

	}









 
	return 0;
}