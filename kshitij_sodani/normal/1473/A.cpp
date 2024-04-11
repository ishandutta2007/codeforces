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
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>it[i];
		}
		sort(it,it+n);
		for(int i=2;i<n;i++){
			it[i]=min(it[i],it[0]+it[1]);

		}
		int st=1;
		for(int i=0;i<n;i++){
			if(it[i]>d){
				st=0;
			}
		}
		if(st){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}

 
 
	
 
	return 0;
}