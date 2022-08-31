
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
		int n,k;
		cin>>n>>k;
		set<int> ss;
		int mi=100;
		for(int i=0;i<n;i++){
			cin>>it[i];
			//ss.insert(it[i]);
			mi=min(mi,it[i]);
		}
		for(int i=0;i<n;i++){
			ss.insert(it[i]-mi);
		}
		if(k==1 and ss.size()>1){
			cout<<-1<<endl;
			continue;
		}
		if(ss.size()==1){
			cout<<1<<endl;
			continue;
		}

		if(k==1){
			cout<<1<<endl;
			continue;
		}

		int cur=ss.size();
		if(cur<=k){
			cout<<1<<endl;
			continue;
		}
		ss.erase(0);
		cur=ss.size();
		int ans=0;
		ans+=(cur)/(k-1);
		if(cur%(k-1)!=0){
			ans+=1;
		}
		cout<<ans<<endl;

	}








	return 0;
}