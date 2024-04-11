#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int L=20;
const int N=1<<L;
int n;
int a[N],b[N];
struct UFS{
	int fa[N];
	void init(int n){
		for(int i=0;i<n;i++)fa[i]=-1;
	}
	int find(int x){
		return fa[x]<0?x:(fa[x]=find(fa[x]));
	}
	bool merge(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y)return false;
		if(fa[x]>fa[y]){
			swap(x,y);
		}
		fa[x]+=fa[y];
		fa[y]=x;
		return true;
	}
};
UFS ufs;
int d[N];
typedef vector<int> VI;
VI es[N];
bool ban[N]={false};
int l[N];
void dfs(int x,int mask){
	while(l[x]<(int)es[x].size()){
		int ei=l[x]++;
		int e=es[x][ei];
		if(!ban[e]){
			int v=(x^a[e]^b[e])&mask;
			ban[e]=true;
			int rev=(a[e]&mask)==x?0:1;
			dfs(v,mask);
			printf("%d %d ",e*2+(1-rev)+1,e*2+rev+1);
		}
	}
}
bool test(int i,bool doit){
	int cnt=1<<i;
	// cerr<<i<<" "<<cnt<<endl;
	for(int i=0;i<cnt;i++){
		d[i]=0;
	}
	for(int i=0;i<n;i++){
		ban[i]=false;
	}
	ufs.init(cnt);
	int ltk=0;
	int mask=(1<<i)-1;
	for(int i=0;i<n;i++){
		int aa=a[i]&mask;
		int bb=b[i]&mask;
		if(ufs.merge(aa,bb))ltk--;
		if(d[aa]++==0)ltk++;
		if(d[bb]++==0)ltk++;
		es[aa].push_back(i);
		es[bb].push_back(i);
	}
	if(ltk!=1){
		goto no;
	}
	for(int i=0;i<cnt;i++){
		if(d[i]%2!=0){
			goto no;
		}
	}
	if(doit){
		for(int i=0;i<cnt;i++){
			l[i]=0;
		}
		printf("%d\n",i);
		for(int i=0;i<cnt;i++){
			if(d[i]>0){
				dfs(i,mask);
				break;
			}
		}
		exit(0);
	}
	else{
		for(int i=0;i<cnt;i++){
			es[i].clear();
		}
		return true;
	}
	no:;
	for(int i=0;i<cnt;i++){
		es[i].clear();
	}
	assert(!doit);
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	int l=0,r=L;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(test(mid,false)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	test(l,true);
	return 0;
}