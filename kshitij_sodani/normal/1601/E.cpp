//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo aa[310001];
vector<llo> adj[310001];
llo co=0;
llo st[310001];
llo par[310001][20];
llo endd[310001];
void dfs(llo no,llo par2=-1){
	par[no][0]=par2;
	st[no]=co;
	co++;
	for(auto j:adj[no]){
	//	cout<<no<<","<<j<<endl;
		dfs(j,no);
	}
	endd[no]=co-1;
}
llo tree[310001];
void u(llo i,llo j){
	while(i<=310000){
		tree[i]+=j;
		i+=(i&-i);
	}
}
llo ss(llo i){
	llo su=0;
	while(i>0){
		su+=tree[i];
		i-=(i&-i);
	}
	return su;
}
vector<pair<pair<llo,llo>,llo>> pre[310001];
pair<llo,llo> xx2[310001];
pair<llo,llo> yy[310001];
vector<pair<llo,llo>> xx[310001];
llo ans[310001];
//add .b to subtree of .a at time i
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,q,k;
	cin>>n>>q>>k;
	for(llo i=0;i<n;i++){
		cin>>aa[i];
	
	}
	for(llo i=0;i<q;i++){
		llo l,r;
		cin>>l>>r;
		l--;
		r--;
		pre[l%k].pb({{l,r},i});
	}
	vector<pair<llo,llo>> re;
	re.pb({0,n});
	for(llo i=n-1;i>=0;i--){
		while(re.size()){
			if(re.back().a>=aa[i]){
				re.pop_back();
			}
			else{
				break;
			}
		}
		adj[re.back().b].pb(i);

		xx2[i]={i,re.back().b-1};
		//cout<<i<<":"<<re.back().b-1<<endl;
		re.pb({aa[i],i});
	//	pair<llo,llo> xx={i,re.back(),b-1};
	//	pair<llo,llo> yy={xx2.a%k,xx2.b%k};
		
	}
	dfs(n);
	for(llo i=0;i<n;i++){

		pair<llo,llo> yy={xx2[i].a%k,xx2[i].b%k};
	//	llo co=(xx2[i].b-xx2[i].a)/(k)+1;
		llo co=((xx2[i].b-xx2[i].a+1))/k;

		u(st[i]+1,aa[i]*(co));
		u(endd[i]+2,-(aa[i]*(co)));
		/*if((yy.b+1)%k==(yy.a)){
			continue;
		}*/
		llo co2=(xx2[i].b-xx2[i].a)/k;
		co2+=1;
		if(co2>co){
			/*if(co>1){
				cout<<i<<"::"<<endl;
				cout<<st[i]<<","<<endd[i]<<endl;
			}*/
			//cout<<i<<":"<<yy.a<<":"<<yy.b<<endl;
			//cout<<co<<endl;
			if(yy.a<=yy.b){
				xx[yy.a].pb({i,1});
				xx[yy.b+1].pb({i,-1});
			}
			else{
				xx[0].pb({i,1});
				xx[yy.b+1].pb({i,-1});
				xx[yy.a].pb({i,1});
			}
		}
	}
	for(llo j=1;j<20;j++){
		for(llo i=0;i<=n;i++){
			if(par[i][j-1]==-1){
				par[i][j]=-1;
			}
			else{
				par[i][j]=par[par[i][j-1]][j-1];
			}
		}
	}
/*	for(llo i=0;i<n;i++){
		cout<<ss(st[i]+1)<<",";
	}
	cout<<endl;*/

	for(llo i=0;i<k;i++){
		for(auto j:xx[i]){
			u(st[j.a]+1,aa[j.a]*j.b);
			u(endd[j.a]+2,-(aa[j.a]*j.b));
		}
		/*for(llo ii=0;ii<n;ii++){
			cout<<ss(st[ii]+1)<<",";
		}
		cout<<endl;*/
		for(auto j:pre[i]){
			if(j.a.b-j.a.a+1<=k){
				ans[j.b]=aa[j.a.a];
				continue;
			}
			ans[j.b]=ss(st[j.a.a]+1);
			llo cur=j.a.a;
			for(llo jj=19;jj>=0;jj--){
				if(par[cur][jj]>=0){
					if(par[cur][jj]<=j.a.b){
						cur=par[cur][jj];
					}
				}
			}
			ans[j.b]-=ss(st[cur]+1);
			//find number of elements with mod i in cur to j.a.b range
			llo xy=cur%k;
			llo cur2=cur;
			//cout<<cur<<":"<<endl;
			if(xy<i){
				cur2+=(i-xy);
			}
			else if(xy>i){
				cur2+=(k-xy)+i;
			}
		//	cout<<cur2<<":"<<endl;
			/*cout<<j.a.a<<","<<j.a.b<<endl;
			cout<<ans[j.b]<<":"<<cur<<endl;
			cout<<endl;*/
			//cout<<cur<<":"<<xy<<":"<<i<<endl;
			if(cur2<=j.a.b){
				ans[j.b]+=(((j.a.b-cur2)/k)+1)*aa[cur];
			}
		}

	}

	for(llo i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}

 
 

 
	return 0;
}