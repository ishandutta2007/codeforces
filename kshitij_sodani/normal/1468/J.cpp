//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo par[200001];
llo find(llo no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
//
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m,k;
		cin>>n>>m>>k;
		for(llo i=0;i<n;i++){
			par[i]=i;
		}
		vector<pair<llo,pair<llo,llo>>> ss;
		llo ans=1e18;
		llo st=0;
		for(llo i=0;i<m;i++){
			llo aa,bb,cc;
			cin>>aa>>bb>>cc;
			aa--;
			bb--;
			ss.pb({cc,{aa,bb}});
			if(cc>k){
				st=-1;
			}

		}
		sort(ss.begin(),ss.end());
		if(st){
			llo mi=-1;
			llo ma=-1;

			for(auto j:ss){
				if(j.a<=k){
					llo x=find(j.b.a);
					llo y=find(j.b.b);
					par[x]=y;
				}
				else{
					if(mi==-1){
						mi=j.a-k;
					}
					/*llo x=find(j.b.a);
					llo y=find(j.b.b);
					if(x!=y){
						if(ma==-1){
							ma=
						}
					}*/
				}
			}
			llo kk=1;
			for(llo i=0;i<n;i++){
				if(find(i)!=find(0)){
					kk=0;
				}
			}
			if(kk==1){
				ans=min(ans,mi);
			}
			else{
				llo cur=0;
				for(auto j:ss){
					if(j.a>k){
						llo x=find(j.b.a);
						llo y=find(j.b.b);
						if(x!=y){
							par[x]=y;
							cur+=j.a-k;
						}
					}
				}
				ans=min(ans,cur);
			}
		}
		if(true){
			reverse(ss.begin(),ss.end());
			llo cot=0;
			for(llo i=0;i<n;i++){
				par[i]=i;
			}
			llo mi=-1;
			for(auto j:ss){
				if(j.a<=k){
					if(mi==-1){
						mi=k-j.a;
					}
					llo x=find(j.b.a);
					llo y=find(j.b.b);
					if(x!=y){
						cot+=k-j.a;
						par[x]=y;
					}
				}
			}
			llo kk=1;
			for(llo i=0;i<n;i++){
				if(find(i)!=find(0)){
					kk=0;
				}
			}
			if(kk){
				ans=min(ans,mi);
			}
		}
		cout<<ans<<endl;





	}




 
	return 0;
}