#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//
//#define endl '\n'
llo n,m;
vector<llo> adj[200001];
llo ind2[200001];
llo ind3[200001];
llo ans=0;
llo tree[800001];
llo tree2[800001];
llo cot[200001];
llo lazy[800001];
void build(llo no,llo l,llo r){
	if(l==r){
		tree[no]=0;
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=min(tree[no*2+1],tree[no*2+2]);
	}
	tree2[no]=r-l+1;
}

void update(llo no,llo l,llo r,llo aa,llo bb,llo val){
	if(lazy[no]!=0){
		tree[no]+=lazy[no];
		if(l<r){
			lazy[no*2+1]+=lazy[no];
			lazy[no*2+2]+=lazy[no];
		}
		lazy[no]=0;
	}
	if(bb<l or aa>r or l>r){
		return;
	}
	if(aa<=l and r<=bb){
		tree[no]+=val;
		if(l<r){
			lazy[no*2+1]+=val;
			lazy[no*2+2]+=val;
		}
	}
	else{
		llo mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb,val);
		update(no*2+2,mid+1,r,aa,bb,val);
		tree[no]=min(tree[no*2+1],tree[no*2+2]);
		if(tree[no*2+1]<tree[no*2+2]){
			tree2[no]=tree2[no*2+1];
		}
		else if(tree[no*2+1]>tree[no*2+2]){
			tree2[no]=tree2[no*2+2];
		}
		else{
			tree2[no]=tree2[no*2+1]+tree2[no*2+2];
		}
	}
}

llo cot2=0;
llo st[200001];
llo endd[200001];
void dfs(llo no){
	st[no]=cot2;
	//cout<<no<<"::"<<cot2<<endl;
	cot2++;
	for(auto j:adj[no]){
		dfs(j);
		
	}
	endd[no]=cot2-1;
}
llo cur[200001];
void dfs2(llo no){
	/*for(llo j=st[ind3[ind2[no]]];j<=endd[ind3[ind2[no]]];j++){
		cur[j]+=1;
	}*/
	update(0,0,cot2-1,st[ind3[ind2[no]]],endd[ind3[ind2[no]]],1);
	/*llo su=0;
	for(llo i=0;i<cot2;i++){
		if(cur[i]==0){
			su+=1;
		}
		//su+=cur[i];
	}
	//cout<<no<<endl;
	for(llo i=0;i<cot2;i++){
		//cout<<cur[i]<<" ";
	}
	//cout<<endl;*/
	//ans-=tree[0];
	if(tree[0]==0){
		ans-=tree2[0];
	}
	////cout<<st[ind3[ind2[no]]]<<"//"<<endd[ind3[ind2[no]]]<<endl;
	////cout<<no<<':'<<tree[0]<<endl;
	for(auto j:adj[no]){
		dfs2(j);
	}
/*	for(llo j=st[ind3[ind2[no]]];j<=endd[ind3[ind2[no]]];j++){
		cur[j]-=1;
	}*/
	update(0,0,cot2-1,st[ind3[ind2[no]]],endd[ind3[ind2[no]]],-1);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	llo ind[n][m];
	llo co=0;
	char s;
	ans=((n*m)/2);
	ans*=ans;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<m;j++){
			cin>>s;
			if(s=='U'){
				ind[i][j]=co;

				co+=1;
				if(i<n-2){
					adj[(i+2)*m+j].pb(i*m+j);
					cot[i*m+j]+=1;
				}

			}
			else if(s=='D'){
				ind[i][j]=ind[i-1][j];
				if(i>1){
					adj[(i-2)*m+j].pb(i*m+j);
					cot[i*m+j]+=1;

				}
			}
			else if(s=='L'){
				ind[i][j]=co;
				co+=1;
				if(j<m-2){
					adj[i*m+j+2].pb(i*m+j);
					cot[i*m+j]+=1;
				}
			}
			else{
				ind[i][j]=ind[i][j-1];
				if(j>1){
					adj[i*m+j-2].pb(i*m+j);
					cot[i*m+j]+=1;
				}
			}
			if((i+j)%2==1){
				ind3[ind[i][j]]=i*m+j;
			}
			ind2[i*m+j]=ind[i][j];
		}
	}
	for(llo i=0;i<n*m;i++){
		for(auto j:adj[i]){
			//cout<<i<<','<<j<<endl;
		}
	}
	for(llo i=0;i<n*m;i++){
		if(((i/m)+(i%m))%2==1){
			if(cot[i]==0){
				dfs(i);
			}
		}
	}
/*	for(llo i=0;i<cot2;i++){
		cur[i]=0;
	}*/
	build(0,0,cot2-1);

	for(llo i=0;i<n*m;i++){
		if(((i/m)+(i%m))%2==0){
			//cout<<i<<"<"<<endl;
			if(cot[i]==0){
				dfs2(i);
			}
		}
	}
	//cout<<cot2<<endl;
	cout<<ans<<endl;









	return 0;
}