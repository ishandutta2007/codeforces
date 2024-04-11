#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
using namespace std;
typedef long long ll;

int st[1<<19][128];

void st_init(int k, int s, int e){
	fore(i,0,100)st[k][i]=i;
	if(s+1<e){
		int m=(s+e)/2;
		st_init(2*k,s,m);
		st_init(2*k+1,m,e);
	}
}
void st_upd(int k, int s, int e, int p, int x, int y){
	if(s+1==e)st[k][x]=y;
	else {
		int m=(s+e)/2;
		if(p<m)st_upd(2*k,s,m,p,x,y);
		else st_upd(2*k+1,m,e,p,x,y);
		fore(i,0,100)st[k][i]=st[2*k+1][st[2*k][i]];
	}
}

int n,q;
int a[200005],x[200005],y[200005];
vector<int> e[200005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i),a[i]--;
	scanf("%d",&q);
	fore(i,0,q){
		int l,r;
		scanf("%d%d%d%d",&l,&r,x+i,y+i);l--;x[i]--;y[i]--;
		e[l].pb(i);e[r].pb(-i-1);
	}
	st_init(1,0,q);
	fore(i,0,n){
		for(int k:e[i]){
			if(k>=0)st_upd(1,0,q,k,x[k],y[k]);
			else {k=-k-1;st_upd(1,0,q,k,x[k],x[k]);}
		}
		printf("%d%c",st[1][a[i]]+1," \n"[i==n-1]);
	}
	return 0;
}