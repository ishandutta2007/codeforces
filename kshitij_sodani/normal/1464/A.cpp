//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo t;
llo n,m;

llo par[100001];
llo find(llo no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n>>m;
		//set<llo> ss;
	//	set<llo> tt;
		//llo ans=0;
	//	llo nn=n;
		for(llo i=0;i<n;i++){
			par[i]=i;
		}
		//llo mm=m;
		map<pair<llo,llo>,llo> kk;
		llo ans=0;
		for(llo i=0;i<m;i++){
			llo aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			if(aa!=bb){
				ans++;
				llo xx=find(aa);
				llo yy=find(bb);
				if(xx==yy){
					ans++;
				}
				else{
					par[xx]=yy;
				}
			}
			/*kk[{aa,bb}]++;
			if(aa!=bb){
				//ans++;
			}
			else{
				nn--;
				mm--;
			}
			ss.insert(aa);
			tt.insert(bb);*/
			//ss.insert()
		}
		cout<<ans<<endl;
		/*llo ans=0;
		llo co=0;

		if(kk.find({j.b,j.a})!=kk.end()){
					co++;
				}


		for(auto k:kk){
			pair<llo,llo> j=k.a;
			if(j.a==j.b){

			}
			else{
				if(ss.find(j.b)!=ss.end() and tt.find(j.a)!=tt.end()){
					co++;
				}
				else{
					ans++;
				}
			}
		}
		cout<<ans<<":"<<co<<endl;
		ans+=(co+(co/2));
		cout<<ans<<endl;*/

		/*if(mm==0){
			cout<<0<<endl;
			continue;
		}*/
	/*	ans=mm;
		llo co=0;
		for(llo i=0;i<n;i++){
			if(ss.find(i)==ss.end() and tt.find(i)==tt.end()){
				co++;
			}
			if(ss.find(i)!=ss.end() and tt.find(i)!=tt.end()){

			}
		}
		nn-=co;
		if(nn==mm){
			cout<<ans+1<<endl;
		}
		else{
			cout<<ans<<endl;
		}*/
		/*cout<<ans<<endl
		;
*/
	}












 
	return 0;
}