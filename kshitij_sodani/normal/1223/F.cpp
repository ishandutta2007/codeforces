#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;

llo q;
llo it[300001];
llo re[300001];
llo ind[300001];
llo su[300001];
map<llo,llo> ss[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>q;
	while(q--){
		llo n;
		cin>>n;
		for(llo i=0;i<=n;i++){
			re[i]=-1;
			ind[i]=i;
			su[i]=0;
			ss[i].clear();
		}
		it[n]=-1;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		llo ans=0;
		for(llo i=n-1;i>=0;i--){
			if(it[i]==it[i+1]){
				re[i]=i+2;
				ind[i]=ind[i+2];
				su[i]=su[i+2]+1;
			}
			else{
				if(re[i+1]==-1){
				}
				else if(ss[ind[re[i+1]]].find(it[i])!=ss[ind[re[i+1]]].end()){
					llo x=ss[ind[re[i+1]]][it[i]];
					re[i]=x+1;
					ind[i]=ind[x+1];
					su[i]=su[x+1]+1;
				}
				else{
					re[i]=-1;
				}
			}
			ss[ind[i]][it[i]]=i;
			ans+=su[i];
		}
		
		cout<<ans<<endl;
	}







	return 0;
}