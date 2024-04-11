#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

vector<llo> it[100001];
llo pre[1000001];
llo val[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		vector<pair<llo,llo>> ss;
		for(llo i=0;i<n;i++){
			it[i].clear();
			llo su=0;
			val[i]=0;
			for(llo j=0;j<m;j++){
				llo aa;
				cin>>aa;
				it[i].pb(aa);
				if(j%2==0){
					su-=aa;
				}
				else{
					su+=aa;
				}
				pre[j+1]=pre[j]+aa;
			}
			for(llo j=1;j<m;j++){
				val[i]+=(pre[j]-(pre[m]-pre[j]));
			}
			ss.pb({val[i],i});
		}
		sort(ss.begin(),ss.end());
		cout<<ss[0].b+1<<" "<<((ss.back().a-ss[0].a)/2)<<endl;
	}








	return 0;
}