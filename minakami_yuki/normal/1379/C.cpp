#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<ctime> 
#define LL long long 
using namespace std;
const int N=1e5+10;
int n,m;
LL ans;
LL p[N];
struct node{
	LL A,B;
}a[N];
bool cmp(node x,node y){
	return x.A>y.A;
}
int get(int x){
	int l=0,r=m,mid;
	while(l!=r){
		mid=l+r+1>>1;
		if(a[mid].A>x) l=mid;
		else r=mid-1;
	}
	return l;
}
int main(){
	//for(int i=1;i<=7;++i) cout<<t[i];
	int T,v;scanf("%d",&T);
	LL now;
	while(T--){
		scanf("%d%d",&n,&m);ans=0;
		for(int i=1;i<=m;++i) scanf("%I64d%I64d",&a[i].A,&a[i].B);
		sort(a+1,a+1+m,cmp);
		//for(int i=1;i<=m;++i) cout<<a[i].A<<" ";cout<<endl;
		for(int i=1;i<=m;++i) p[i]=p[i-1]+a[i].A; 
		for(int i=1;i<=m;++i){
			v=get(a[i].B);
			//cout<<i<<" "<<v<<endl;
			if(i<=v) {
				if(n<v) now=p[n];
				else now=p[v]+(LL)(n-v)*(LL)a[i].B;
			}
			else {
				if(n<v+1) now=p[n];
				else now=p[v]+a[i].A+(LL)(n-v-1)*(LL)a[i].B;
			}
			ans=max(ans,now);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}