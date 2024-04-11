#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int n,flag;
int col[N],dg[N];
int c1[N],c2[N];

void dfs(int k,int fa){
	fore(k)if(_to!=fa){
		dfs(_to,k);
		if(col[_to])c1[k]++;
		else c2[k]++;
	}
	if(k!=1){// if not root, get the color of edge to father
		if(c1[k]<=c2[k])col[k]=1,c1[k]++;
		else col[k]=0,c2[k]++;
	}
	if(c1[k]!=(dg[k]+1)/2||c2[k]!=dg[k]/2)flag=1;
}

void clear(){
	S=0;flag=0;
	for(int i=1;i<=n;i++)hd[i]=dg[i]=c1[i]=c2[i]=0;
}

void df5(int k,int fa){
	basic_string<int> a,b;
	if(fa)(col[k]?a:b)+=fa;
	fore(k)if(_to!=fa)(col[_to]?a:b)+=_to;
	auto push=[&](int x){if(x==fa)cout<<k<<' '<<fa<<endl;else df5(x,k);};
	if(a.size()>b.size())push(a[0]);
	for(int i=a.size()>b.size(),j=0;i<a.size();i++,j++)
		push(b[j]),push(a[i]);
}

void solve(){
	cin>>n;
	clear();
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x);
		dg[x]++,dg[y]++;
	}
	dfs(1,0);// get color for each edge
	if(flag)cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		df5(1,0);
	} 
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}