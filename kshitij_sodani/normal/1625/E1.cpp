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
llo re[300001];
llo le[300001];
llo par3[300001];
llo val[300001];
llo st[300001];
llo endd[300001];
llo co=0;
vector<llo> adj[300001];
llo tree[300001];
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

void dfs(llo no,llo par=-1){
	val[no]=1;

	llo x=0;
	if(no<n){
		st[no]=co;
		co++;
	}
	for(auto j:adj[no]){
		dfs(j,no);
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

llo par[300001][20];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	string s;
	cin>>s;
	vector<llo> ss5;
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
		llo su=1;
		llo cur=l;
		for(llo j=19;j>=0;j--){
			if(par[cur][j]<=r and par[cur][j]!=-1){
				cur=par[cur][j];
				su+=(1<<j);
			}
		}
		llo ans=((su*(su-1)))/2;
	//	cout<<su<<"::"<<endl;
		llo ind2=endd[cur]+1;
		
		//cout<<cur<<"::"<<endl;
		//cout<<st[l]<<"::"<<ind2<<endl;
		ans+=ss(ind2)-ss(st[l]);
		cout<<ans<<endl;
	}



 
	return 0;
}