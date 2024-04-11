#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,m;
vector<pair<int,pair<int,int> > > w[100005];

int p[45];
int v[45];
int g[45][45];

int main(){
	fore(i,1,45)fore(j,1,45)g[i][j]=__gcd(i,j);
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		int k;
		scanf("%d",&k);
		fore(j,0,k){
			int x;
			scanf("%d",&x);
			w[x].pb(mp(i,mp(j,k)));
		}
	}
	fore(_,1,m+1){
		memset(v,-1,sizeof(v));
		int l=-1;
		int r=0;
		fore(j,0,w[_].size()){
			int i=w[_][j].fst;
			int x=w[_][j].snd.fst;
			int k=w[_][j].snd.snd;
			if(j==0||i>w[_][j-1].fst+1){
				l=i;
			}
			else {
				fore(kk,1,45){
					if(v[kk]<0)continue;
					int kkk=g[k][kk];
					if(v[kk]%kkk!=x%kkk)l=max(l,p[kk]+1);
				}
			}
			p[k]=i;
			v[k]=x;
			r=max(r,i-l+1);
		}
		printf("%d\n",r);
	}
	return 0;
}