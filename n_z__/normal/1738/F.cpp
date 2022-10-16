#include <bits/stdc++.h>
#define int long long
using namespace std;
int tg[1005];
int dk[1005];
int top=0;
struct node{
	int d,pos;
}a[1005]; 
int bel[1005];
int tt[1005];
bool cmp(node x,node y){
	return x.d>y.d;
}
void dfs(int i){
	tg[i]=1;
	vector<int> tmp;
	while(tt[i]--){
		cout<<"? "<<i<<endl;
		fflush(stdout);
		int v;
		cin>>v;
		if(!tg[v]){
			tg[v]=1;
			tmp.push_back(v);
		}
		else{
			bel[i]=bel[v];
			dk[v]=1;
			break;
		}
	}
	if(!bel[i]) bel[i]=++top;
	for(auto v:tmp){
		bel[v]=bel[i];
	}
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(tg,0,sizeof(tg));
		memset(bel,0,sizeof(bel));
		top=0;
		for(int i=1;i<=n;i++) cin>>a[i].d;
		for(int i=1;i<=n;i++) a[i].pos=i,tt[i]=a[i].d;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++) if(!tg[a[i].pos]) dfs(a[i].pos);
		cout<<"! ";
		for(int i=1;i<=n;i++) cout<<bel[i]<<" ";
		cout<<endl;
		fflush(stdout);
	}
	return 0;
}