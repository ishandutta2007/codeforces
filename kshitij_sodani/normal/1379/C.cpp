#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo pre[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		vector<pair<llo,llo>> aa;
		for(llo i=0;i<m;i++){
			llo bb,cc;
			cin>>bb>>cc;
			aa.pb({bb,cc});
		}
		sort(aa.begin(),aa.end());
		reverse(aa.begin(),aa.end());
		for(llo i=1;i<m+1;i++){
			pre[i]=pre[i-1]+aa[i-1].a;
		}
		llo ans=0;
		ans=max(ans,pre[min(n,m)]);

		for(llo i=0;i<m;i++){
			if(aa[i].b>=aa[0].a){
				ans=max(ans,aa[i].a+(n-1)*aa[i].b);
				continue;
			}
			llo low=0;
			llo high=min(m-1,n-1);
			while(low<high-1){
				llo mid=(low+high)/2;
				if(aa[mid].a>aa[i].b){
					low=mid;
				}
				else{
					high=mid;
				}
			}
			llo ind=low;
			if(aa[high].a>aa[i].b){
				ind=max(ind,high);
			}
			if(ind>=i){
				ans=max(ans,pre[ind+1]+aa[i].b*(n-ind-1));
			}
			else{
				if(ind+1==n){
					continue;
				}
				ans=max(ans,pre[ind+1]+aa[i].a+(n-ind-2)*aa[i].b);
			}
		}
		cout<<ans<<endl;


	}
	




 
 
	return 0;
}