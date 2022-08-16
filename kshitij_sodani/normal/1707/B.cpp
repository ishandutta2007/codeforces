#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo it[100001];
llo ss[500001];
llo vis[500001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		map<llo,llo> ss;
		vector<llo> ee;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(i>0){
				ss[it[i]-it[i-1]]++;
				/*if(vis[it[i]-it[i-1]]==0){
					ee.pb(it[i]-it[i-1]);
					vis[it[i]-it[i-1]]=1;
				}*/
			}
		}
		for(llo i=0;i<n-2;i++){

			map<llo,llo> tt;
			llo st=0;
			llo pre=-1;
			for(auto j:ss){
				st++;
				if(st>1){
					tt[j.a-pre]++;
				}
				if(j.b>1){
					tt[0]+=j.b-1;
				}
				pre=j.a;
			}
			swap(ss,tt);
		}
		for(auto j:ss){
			if(j.b>0){
				cout<<j.a<<endl;
			}
		}

	}









	return 0;
}