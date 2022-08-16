#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int it[100001];
int cc[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		vector<int> tt;
		vector<int> ind;
		for(int i=0;i<n;i++){
			cin>>it[i];
			if(it[i]<=q){
				tt.pb(i);
			}
		}
		if(q>=n){
			for(int i=0;i<n;i++){
				cout<<1;
			}
			cout<<endl;
			continue;
		}
		int cur=0;
		int ans=0;
		for(int i=n-1;i>=0;i--){
			if(it[i]<=cur){
				if(cur==0){
					cur=1;
				}
				ans++;
				cc[i]=1;
			}
			else if(cur<q){
				cur++;
				cc[i]=1;
			}
			else{
				cc[i]=0;
			}
		}
		for(int i=0;i<n;i++){
			cout<<cc[i];
		
		}
		cout<<endl;
	//	cout<<ans<<endl;



		
	}









	return 0;
}