//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int t;
int it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>it[i];
		}
		int l=0;
		int r=n-1;
		while(l<r){
			if(it[l]==it[r]){
				l++;
				r--;
				continue;
			}
			break;
		}
		if(l>=r){
			cout<<"YES"<<endl;
			continue;
		}
		vector<int> tt;
		tt.pb(it[l]);
		tt.pb(it[r]);
		int st=0;
		for(auto j:tt){
			int stt=1;
			int ll=0;
			int rr=n-1;
			while(ll<rr){
				if(it[ll]==it[rr]){
					ll++;
					rr--;
					continue;
				}
				if(it[ll]==j){
					ll++;
				}
				else if(it[rr]==j){
					rr--;
				}
				else{
					stt=0;
					break;
				}
			}
			st+=stt;
		}
		if(st>0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
	}



 
	return 0;
}