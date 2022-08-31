//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int ask(vector<int> aa){
	cout<<"? "<<aa.size()<<" ";
	for(auto j:aa){
		cout<<j+1<<" ";
	}
	cout<<endl;
	int x;
	cin>>x;
	return x;
}
int ans[1001];
int ind[1001];

int n,k;
void solve(int l,int r,int ma){
	if(l==r){
		//cout<<l<<":"<<endl;
		for(int i=0;i<k;i++){
			if(i!=ind[l]){
				ans[i]=ma;
			//	cout<<i<<":"<<ma<<endl;
			}
		}
		if(ind[l]>-1){
			vector<int> ss;
			for(int i=0;i<n;i++){
				if(ind[i]!=ind[l]){
					ss.pb(i);
				}
			}
			ans[ind[l]]=ask(ss);
		}
	}
	else{
		int mid=(l+r)/2;
		vector<int> ac;
		for(int i=l;i<=mid;i++){
			ac.pb(i);
		}
		int xx=ask(ac);
		if(xx==ma){
			solve(l,mid,ma);
		}
		else{
			solve(mid+1,r,ma);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;i++){
			ind[i]=-1;
		}
		for(int i=0;i<k;i++){
			int x;
			cin>>x;
			for(int j=0;j<x;j++){
				int y;
				cin>>y;
				y--;
				ind[y]=i;
			}
		}
		vector<int> ac;
		for(int i=0;i<n;i++){
			ac.pb(i);
		}
		int xx=ask(ac);
		solve(0,n-1,xx);

		cout<<"! ";
		for(int i=0;i<k;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;

		string s;
		cin>>s;

	}



	return 0;
}