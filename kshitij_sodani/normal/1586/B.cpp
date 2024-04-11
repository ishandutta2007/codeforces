//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		set<int> ss;
		for(int i=1;i<=n;i++){
			ss.insert(i);
		}
		for(int i=0;i<m;i++){
			int aa,bb,cc;
			cin>>aa>>bb>>cc;
			ss.erase(bb);
		}
		int x=*(ss.begin());
		for(int i=1;i<=n;i++){
			if(i!=x){
				cout<<x<<" "<<i<<endl;
			}
		}
	}
 	
 
 

 
	return 0;
}