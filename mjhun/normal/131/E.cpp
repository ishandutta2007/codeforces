#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,m;
int s[9];
int x[100005],y[100005];
vector<int> r[100005],c[100005],d0[200005],d1[200005];

int fnd(vector<int> *v, int x, int y){
	int k=lower_bound(v[x].begin(),v[x].end(),y)-v[x].begin();
	int r=0;
	r+=k>0;
	r+=k<v[x].size()-1;
	return r;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,m){
		scanf("%d%d",x+i,y+i);x[i]--;y[i]--;
		r[x[i]].pb(y[i]);
		c[y[i]].pb(x[i]);
		d0[x[i]+y[i]].pb(n+x[i]-y[i]);
		d1[n+x[i]-y[i]].pb(x[i]+y[i]);
	}
	fore(i,0,n)sort(r[i].begin(),r[i].end()),sort(c[i].begin(),c[i].end());
	fore(i,0,2*n)sort(d0[i].begin(),d0[i].end()),sort(d1[i].begin(),d1[i].end());
	fore(i,0,m){
		int w=0;
		w+=fnd(r,x[i],y[i]);
		w+=fnd(c,y[i],x[i]);
		w+=fnd(d0,x[i]+y[i],n+x[i]-y[i]);
		w+=fnd(d1,n+x[i]-y[i],x[i]+y[i]);
		s[w]++;
	}
	fore(i,0,9){
		if(i)putchar(' ');
		printf("%d",s[i]);
	}
	puts("");
	return 0;
}