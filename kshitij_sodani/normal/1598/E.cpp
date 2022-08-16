//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
vector<pair<llo,llo>> pp[100001];
vector<llo> tt[100001];
vector<pair<llo,llo>> ind[1001][1001];;
llo vis[1001][1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m,q;
	cin>>n>>m>>q;
	llo xx=0;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<m;j++){
			vis[i][j]=1;
		}
	}

	for(llo i=0;i<n-1;i++){
		for(llo j=0;j<m;j++){

			if(i==0){
				xx++;
				if(j>0){
					pp[xx].pb({i,j-1});
				}
				pair<llo,llo> cur={i,j};
				llo st=1;
				while(cur.a<n and cur.b<m){
					pp[xx].pb(cur);
					if(st==1){
						cur.a+=1;
					}
					else{
						cur.b+=1;

					}
					st^=1;
				}
				for(llo jj=0;jj<pp[xx].size();jj++){
					ind[pp[xx][jj].a][pp[xx][jj].b].pb({xx,jj});
					tt[xx].pb(1);
				}
			}
			else if(j==0){
				xx++;
				pair<llo,llo> cur={i,j};
				llo st=1;
				while(cur.a<n and cur.b<m){
					pp[xx].pb(cur);
					if(st==1){
						cur.a+=1;
					}
					else{
						cur.b+=1;

					}
					st^=1;
				}
				for(llo jj=0;jj<pp[xx].size();jj++){
					ind[pp[xx][jj].a][pp[xx][jj].b].pb({xx,jj});
					tt[xx].pb(1);
				}
			}
		}
	}
	llo cot=n*m;
	llo su=0;
	llo ans=0;
	for(llo j=1;j<=xx;j++){
		llo nn=pp[j].size();
		/*for(auto  jj:pp[j]){
			cout<<jj.a<<","<<jj.b<<" : ";
		}
		cout<<endl;*/
		if(nn>1){
			ans=(ans+((nn*(nn-1))/2));
		}
	}
	/*cout<<ans<<endl;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<m;j++){
			cout<<ind[i][j].size()<<".";
		}
		cout<<endl;
	}*/
	//cout<<ans<<"::"<<endl;
	while(q--){
		llo x,y;
		cin>>x>>y;
		x--;
		y--;
		if(n==1){
			vis[x][y]^=1;
			llo fin=0;
			llo ac=0;
			for(llo i=0;i<m;i++){
				if(vis[0][i]==0){
					ac=0;
				}
				else{
					fin+=min(ac,(llo)1);
					ac++;
					fin++;
				}
			}
			cout<<fin<<endl;



			continue;

		}
		llo fac=-1;
		llo fi=1;
		
		if(vis[x][y]==0){
			//making it active
			fac=1;
			fi=1;
		}
		for(auto jj:ind[x][y]){
			llo ind2=jj.b;
			llo le=0;
			for(llo kk=ind2-1;kk>=0;kk--){
				if(tt[jj.a][kk]==0){
					break;
				}
				le++;
			}
			llo re=0;
			for(llo kk=ind2+1;kk<tt[jj.a].size();kk++){
				if(tt[jj.a][kk]==0){
					break;
				}
				re++;
			}
			//cout<<jj.a<<":"<<le<<":"<<re<<endl;
			ans+=fac*(le+re+le*re);
			tt[jj.a][ind2]^=1;
		}

		cot-=vis[x][y];
		vis[x][y]^=1;
		cot+=vis[x][y];
		//llo ans=cot+su;
		cout<<ans+cot<<endl;

	}
	
 
 
	return 0;
}