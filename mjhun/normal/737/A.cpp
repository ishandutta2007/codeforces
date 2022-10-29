#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int n,k,l,t;
pair<int,int> x[200005];
int g[200005];

bool can(int _){
	int c=x[_].snd;
	ll tt=0;
	fore(i,0,k-1){
		int w=g[i+1]-g[i];
		if(w>c)return false;
		tt+=w+max(2*w-c,0);
	}
	return tt<=t;
}

int main(){
	scanf("%d%d%d%d",&n,&k,&l,&t);
	fore(i,0,n){
		int c,v;
		scanf("%d%d",&c,&v);
		x[i]=mp(c,-v);
	}
	sort(x,x+n);
	fore(i,0,n)x[i].snd*=-1;
	fore(i,1,n)x[i].snd=max(x[i].snd,x[i-1].snd);
	fore(i,1,k+1)scanf("%d",g+i);
	sort(g+1,g+k+1);
	g[k+1]=l;
	k+=2;
	int s=0,e=n+1;
	while(e-s>1){
		int m=(s+e)/2;
		if(can(m-1))e=m;
		else s=m;
	}
	if(s==n)puts("-1");
	else printf("%d\n",x[s].fst);
	return 0;
}