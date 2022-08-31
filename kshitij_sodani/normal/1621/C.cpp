//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int ans[10001];
int ask(int i){
	cout<<"? "<<i+1<<endl;
	int x;
	cin>>x;
	return x-1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<int> cur;
		for(int i=0;i<n;i++){
			cur.insert(i);
		}
		int su=0;
		while(cur.size()){
			
			//int j=*cur.begin();
			int j=*(cur.begin());
			
			vector<int> zz;
			int ba=su;
			while(true){
				su++;
				zz.pb(ask(j));
				if(zz.size()>1){
					if(zz[0]==zz.back()){
						zz.pop_back();
						break;
					}
				}
			}
			vector<int> zz2=zz;
			for(int i=0;i<zz.size();i++){
				cur.erase(zz2[i]);
				zz[(i+ba)%zz.size()]=zz2[i];
			}
			for(int i=0;i<zz.size();i++){
				ans[zz[i]]=(zz[(i+1)%zz.size()]);
			}
		}
		cout<<"! ";
		for(int i=0;i<n;i++){
			cout<<ans[i]+1<<" ";
		}
		cout<<endl;
	}






 
	return 0;
}