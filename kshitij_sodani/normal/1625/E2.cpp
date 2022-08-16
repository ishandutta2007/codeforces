//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n,q;
llo re[300002];
llo le[300002];
llo par3[300002];
llo val[300002];
llo st[300002];
llo endd[300002];
llo co=0;
vector<llo> adj[300002];
llo tree[300002];
void u(llo i,llo j){
	while(i<=n){
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
vector<llo> lev[300002];
llo zz[300002];
llo ind[300002];
vector<llo> tree2[300002];
llo yy[300002];
void uu(llo i,llo j,llo ind5){
	while(i<tree2[ind5].size()){
		tree2[ind5][i]+=j;
		i+=(i&-i);
	}
}
llo ss2(llo i,llo ind5){
	llo su=0;
	while(i>0){
		su+=tree2[ind5][i];
		i-=(i&-i);
	}	
	return su;
}
void dfs(llo no,llo levv=0){
	zz[no]=levv;
	val[no]=1;
	ind[no]=lev[levv].size();
	lev[levv].pb(no);
	if(tree2[levv].size()==0){
		tree2[levv].pb(0);
		tree2[levv].pb(0);
	}
	tree2[levv].pb(0);
	llo x=0;
	if(no<n){
		st[no]=co;
		co++;
	}
	for(auto j:adj[no]){
		dfs(j,levv+1);
		yy[no]++;
		x++;
		//val[no]+=val[j];
	}
	val[no]+=((x*(x-1))/2);
	if(no<n){
		//cout<<st[no]+1<<",,"<<val[no]<<endl;
		u(st[no]+1,val[no]);
	}
	endd[no]=co-1;
}

llo par[300002][20];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	string s;
	cin>>s;
	vector<llo> ss5;
	tree2[0].pb(0);
	for(llo i=0;i<n;i++){
		re[i]=-1;
		le[i]=-1;
		par3[i]=-1;
	}
	for(llo i=0;i<n;i++){
		if(s[i]=='('){
			ss5.pb(i);
		}
		else{
			if(ss5.size()==0){
				continue;
			}
			re[ss5.back()]=i;//=ss5.back();
			le[i]=ss5.back();
			ss5.pop_back();
		}
	}
	for(llo i=0;i<n;i++){
		if(re[i]!=-1){
			llo cur=i+1;
			while(cur<re[i]){
				adj[i].pb(cur);
				par3[cur]=i;
				cur=re[cur]+1;
			}
		}
	}
	for(llo i=0;i<n;i++){
		if(re[i]!=-1){
			if(par3[i]==-1){
				adj[n].pb(i);
				par3[i]=n;
			}
		}
	}
	for(llo i=0;i<n;i++){
		if(re[i]!=-1){
			//cout<<i<<":"<<par3[i]<<endl;
			//cout<<i<<":"<<re[i]<<endl;
		}
	}
	dfs(n);
	for(llo i=0;i<=n;i++){
		par[i][0]=-1;
		if(i<n){
			if(re[i]>=0){
				par[i][0]=re[i]+1;
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
	
	st[n]=n;
	endd[n]=n;
	le[n]=-1;
	re[n]=-1;
	par3[n]=-1;
	for(llo i=0;i<n;i++){
		if(re[i]!=-1){
			//cout<<i<<endl;
		//	cout<<st[i]<<","<<endd[i]<<endl;
		}
	}
	while(q--){
		llo tt,l,r;
		cin>>tt>>l>>r;
		l--;
		r--;
		if(tt==1){
		//	cout<<st[l]+1<<".."<<val[l]<<endl;
		//	cout<<ss(st[l]+1)<<"<<"<<endl;

			u(st[l]+1,-1);
			if(par3[l]!=n){
				yy[par3[l]]--;

				u(st[par3[l]]+1,-(yy[par3[l]]));
			}
			//cout<<ss(st[l]+1)<<"<<"<<endl;
			//handle
			uu(ind[l]+1,1,zz[l]);
			continue;
		}
		llo su=1;
		llo cur=l;
		for(llo j=19;j>=0;j--){
			if(par[cur][j]<=r and par[cur][j]!=-1){
				cur=par[cur][j];
				su+=(1<<j);
			}
		}
		su-=(ss2(ind[cur]+1,zz[cur])-ss2(ind[l],zz[cur]));
	//	cout<<(ss2(ind[cur]+1,zz[cur])-ss2(ind[l],zz[cur]))<<"?"<<endl;
		llo ans=((su*(su-1)))/2;
	//	cout<<su<<"::"<<endl;
		llo ind2=endd[cur]+1;
		//cout<<su<<":::"<<endl;
		//cout<<cur<<"::"<<endl;
		//cout<<st[l]<<"::"<<ind2<<endl;
		ans+=ss(ind2)-ss(st[l]);
	//	cout<<ss(ind2)<<"{{"<<endl;
		cout<<ans<<endl;
	}



 
	return 0;
}