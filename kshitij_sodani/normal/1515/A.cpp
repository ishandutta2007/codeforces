//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


int it[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		int su=0;
		for(int i=0;i<n;i++){
			cin>>it[i];
			su+=it[i];
		}
		if(su==x){
			cout<<"NO"<<endl;
			continue;
		}
		if(su<x){
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++){
				cout<<it[i]<<" ";
			}
			cout<<endl;
			continue;
		}
		sort(it,it+n);
		int cur=0;
		for(int i=0;i<n;i++){
			cur+=it[i];
			if(cur==x){
				swap(it[i],it[i+1]);
				break;
			}
		}
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			cout<<it[i]<<" ";
		}
		cout<<endl;


	}









	return 0;
}