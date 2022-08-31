//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[200001];
llo pp=0;
llo cc=0;
bool check(llo no){
	llo le=pp;
	llo ind=no;
	for(llo i=0;i<=no;i++){
		/*if(le==cc){
			return false;
		}*/
		if(le==cc+1){
			le=1;
		}
		if(le==0){
			return false;
		}
		if(it[ind]>=le){
			return false;
		}

		le--;

		ind--;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n,m,aa,bb;
		cin>>n>>m>>aa>>bb;
		aa--;
		bb--;

		if(aa>bb){
			aa=n-1-aa;
			bb=n-1-bb;
		}
		llo le=bb;
		pp=le;
		cc=aa;
		for(llo i=0;i<m;i++){
			cin>>it[i];
		}
		sort(it,it+m);
		llo ans=0;
		//cout<<le<<":"<<endl;

		if(check(0)){
			llo low=0;
			llo high=m-1;
			while(low<high-1){
				llo mid=(low+high)/2;
				if(check(mid)){
					low=mid;
				}
				else{
					high=mid;
				}
			}
			ans=low+1;
			if(check(high)){
				ans=max(ans,high+1);
			}
		}
		/*for(llo i=0;i<m;i++){
			if(le>0){
				if(it[i]<le){
					ans++;
				}
				le--;
			}
		}*/

		cout<<ans<<endl;
	}


 
	return 0;
}