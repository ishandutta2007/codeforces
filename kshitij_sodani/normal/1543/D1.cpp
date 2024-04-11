//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

bool ask(int i){
	cout<<i<<endl;
	int x;
	cin>>x;
	return x;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> ss;
		int cur=0;
		for(int i=0;i<n;i++){
			if(ask(cur^i)){
				break;
			}
			cur=i;
		}
		/*for(int i=0;i<n;i++){
			ss.pb(i);
		}
		int st=0;
		while(true){
			set<int> xx;
			int cur=0;
			int ok=1;
			for(auto j:ss){
				cur^=j;
				if(cur>=n){
					cur=0;
				}
				xx.insert(cur);
			}
			if(xx.size()<n){
				ok=0;
			}
			st|=ok;
			if(next_permutation(ss.begin(),ss.end())){
				continue;
			}
			break;
		}
		cout<<st<<endl;*/
	}



 
 
 
 
 
 
 
	return 0;
}