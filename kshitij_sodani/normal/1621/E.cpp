//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
vector<llo> pre2[100001];
llo su2[100001];
llo ans[200001];
llo co[100001];
llo pre[100001][3];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		vector<llo> aa;
		for(llo i=0;i<n;i++){
			llo dd;
			cin>>dd;
			aa.pb(dd);
		}
		sort(aa.begin(),aa.end());
		reverse(aa.begin(),aa.end());
		while(aa.size()>m){
			aa.pop_back();
		}
		reverse(aa.begin(),aa.end());
		vector<pair<llo,llo>> zz;
		llo xo=0;
		for(llo i=0;i<m;i++){
			pre2[i].clear();
			llo x;
			cin>>x;
			xo+=x;
			llo su=0;
			if(i>0){
				co[i]=co[i-1]+pre2[i-1].size();
			}
			for(llo j=0;j<x;j++){
				llo bb;
				cin>>bb;
				su+=bb;
				pre2[i].pb(bb);
			}
			su2[i]=su;
			zz.pb({(su+x-1)/x,i});
		}
		sort(zz.begin(),zz.end());

		for(llo i=0;i<m;i++){
			for(llo j=0;j<3;j++){
				pre[i+1][j]=pre[i][j];
				if((i+(j-1))>=0 and i+(1<j-1)<m){
					if(zz[i].a>aa[i+j-1]){
						pre[i+1][j]+=1;
					}
				}
			}
		}
		//0-left
		//1-normal
		//2 right
		llo ind=-1;

		for(auto jj:zz){
			ind++;
			llo co3=pre2[jj.b].size();
			for(llo i=0;i<pre2[jj.b].size();i++){
				llo cur=(su2[jj.b]-pre2[jj.b][i]+co3-2)/(co3-1);
				//cout<<su2[jj.b]<<":"<<cur<<endl;
				if(cur>jj.a){
					llo st=1;
					pair<llo,llo> ne={cur+1,-1};
					llo j=lower_bound(zz.begin(),zz.end(),ne)-zz.begin()-1;
					if(ind>0){
						if(pre[ind][1]>0){
							st=0;
						}
					}
					if(j+1<zz.size()){
						if(pre[zz.size()][1]>pre[j+1][1]){
							st=0;
						}
					}
					if(pre[j+1][0]-pre[ind+1][0]>0){
						st=0;
					}
					if(cur>aa[j]){
						st=0;
					}
					ans[i+co[jj.b]]=st;

				}
				else{
					llo st=1;
					pair<llo,llo> ne={cur,-1};
					llo j=lower_bound(zz.begin(),zz.end(),ne)-zz.begin();
					//cout<<j<<"::"<<endl;
					if(pre[j][1]>0){
						st=0;
					}
					if(pre[zz.size()][1]>pre[ind+1][1]){
						st=0;
					}
					if(cur>aa[j]){
						st=0;
					}
					if(pre[ind][2]-pre[j][2]>0){
						st=0;
					}
					ans[i+co[jj.b]]=st;
				}
			}
		}
		for(llo i=0;i<xo;i++){
			cout<<ans[i];
		}
		cout<<endl;
	}	






 
	return 0;
}