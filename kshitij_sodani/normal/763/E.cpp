#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
vector<llo> tree[4*100001];
llo tree2[4*100001];
llo adj[100001][11];
llo n,k;
llo par[100001];
llo find2(llo no){
	if(par[no]==no){
		return no;
	}
	par[no]=find2(par[no]);
	return par[no];
}
pair<llo,llo> cur;
llo find(llo no,llo ind){
	if(tree[ind][no-cur.a]==no){
		return no;
	}
	tree[ind][no-cur.a]=find(tree[ind][no-cur.a],ind);
	return tree[ind][no-cur.a];
}
void build(llo no,llo l,llo r){
	if(l==r){
		tree[no].pb(l);
		tree2[no]=1;
	}
	else{

		llo mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		cur={l,r};
		for(llo i=l;i<=r;i++){
			if(i<=mid){
				tree[no].pb(tree[no*2+1][i-l]);
			}
			else{
				tree[no].pb(tree[no*2+2][i-(mid+1)]);
			}
		}

		for(llo i=mid;i>=mid-k+1;i--){
			if(i<l){
				break;
			}
			for(llo j=mid+1;j-i<=k;j++){
				if(j>r){
					break;
				}
				if(adj[i][j-i+5]){

					llo x=find(i,no);
					llo y=find(j,no);
					if(x==y){
					}
					else{
						tree[no][x-l]=y;
					}
				}
			}
		}
		
		for(llo i=l;i<=r;i++){
			find(i,no);
			if(tree[no][i-l]==i){
				tree2[no]++;
				
			}
		}
	}

}
vector<pair<pair<llo,llo>,llo>> ss;
llo query(llo no,llo l,llo r,llo aa,llo bb){
	if(r<aa or l>bb){
		return 0;
	}
	if(aa<=l and r<=bb){
		ss.pb({{l,r},no});
		return tree2[no];
	}
	else{
		llo mid=(l+r)/2;
		llo x=query(no*2+1,l,mid,aa,bb);
		llo y=query(no*2+2,mid+1,r,aa,bb);
		return x+y;
	}
}
llo vis[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	llo m;
	cin>>m;
	for(llo i=0;i<m;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		if(aa>bb){
			swap(aa,bb);
		}
		adj[aa][(bb-aa)+5]=1;
		adj[bb][aa-bb+5]=1;
	}
	for(llo i=0;i<n;i++){
		par[i]=i;
	}
	build(0,0,n-1);
	llo q;
	cin>>q;
	while(q--){
		llo l,r;
		cin>>l>>r;
		l--;
		r--;
		ss.clear();
		llo ans=query(0,0,n-1,l,r);
		vector<llo> tt;
		
		for(llo i=0;i+1<ss.size();i++){
			
			for(llo ii=ss[i].a.b;ii>=ss[i].a.b-k;ii--){
				if(ii<ss[i].a.a){
					break;
				}
				llo cur=i;
				for(llo j=1;j<=k;j++){
					
					if(ii+j>ss[cur].a.b){
						cur++;
					}
					
					if(cur>=ss.size()){
						break;
					}
					if(adj[ii][j+5] and cur>i){
						llo x=tree[ss[i].b][ii-ss[i].a.a];
						llo y=tree[ss[cur].b][ii+j-ss[cur].a.a];
						if(vis[x]==0){
							vis[x]=1;
							tt.pb(x);

						}
						x=find2(x);
						if(vis[y]==0){
							vis[y]=1;
							tt.pb(y);
						}
						y=find2(y);
						par[x]=y;

					}

				}

			}

			
		}
		for(auto j:tt){
			if(par[j]!=j){
				ans--;
			}
			par[j]=j;
			vis[j]=0;
		}
		cout<<ans<<endl;

	}
	




	return 0;
}