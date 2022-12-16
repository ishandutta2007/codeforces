#include<bits/stdc++.h>
using namespace std;
typedef long long Ll;
typedef vector<int> VI;
typedef VI::iterator IT;
const int N=200200;
VI ins[N];
VI outs[N];
int lk[N]={0};
int ord[N];
int ort=0;
void gg(){
	puts("-1");
	exit(0);
}
int chmn[N];
int pamn[N];
char result[N]={'\0'};
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ins[v].push_back(u);
		outs[u].push_back(v);
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		lk[i]=ins[i].size();
		if(lk[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		ord[++ort]=x;
		for(IT it=outs[x].begin();it!=outs[x].end();it++){
			if(--lk[*it]==0){
				q.push(*it);
			}
		}
	}
	if(ort!=n){
		gg();
	}
	for(int i=1;i<=n;i++){
		int x=ord[i];
		pamn[x]=x;
		for(IT it=ins[x].begin();it!=ins[x].end();it++){
			pamn[x]=min(pamn[x],pamn[*it]);
		}
	}
	for(int i=n;i>=1;i--){
		int x=ord[i];
		chmn[x]=x;
		for(IT it=outs[x].begin();it!=outs[x].end();it++){
			chmn[x]=min(chmn[x],chmn[*it]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bool w=min(pamn[i],chmn[i])==i;
		result[i]=w?'A':'E';
		if(w){
			ans++;
		}
	}
	printf("%d\n%s\n",ans,result+1);
	return 0;
}