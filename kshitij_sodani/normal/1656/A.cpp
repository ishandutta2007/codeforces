
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*vector<int> ss;
	for(int i=2;i<=1e5;i++){
		if(vis[i]==0){
			ss.pb(i);
			for(int j=i;j<=1e5;j+=i){
				vis[j]=1;
			}
		}
	}*/
	llo t;
	cin>>t;

	while(t--){
		llo n;	
		cin>>n;
		pair<llo,llo> mi={1e9,1e9};
		pair<llo,llo> ma={0,0};
		for(int i=0;i<n;i++){
			cin>>it[i];
			ma=max(ma,{it[i],i});
			mi=min(mi,{it[i],i});
		}
		cout<<mi.b+1<<" "<<ma.b+1<<endl;




	}






	return 0;
}