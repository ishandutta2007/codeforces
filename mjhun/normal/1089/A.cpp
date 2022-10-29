#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

bool vis[4][4][256][256];
pair<pair<int,int>,pair<int,int> > f[4][4][256][256];

void dfs(int k0, int k1, int p0, int p1);

bool asd(int k0, int k1, int p0, int p1, int kk0, int kk1, int pp0, int pp1){
	if(pp0>205||pp1>205)return false;
	if(vis[kk0][kk1][pp0][pp1])return true;
	f[kk0][kk1][pp0][pp1]=mp(mp(k0,k1),mp(p0,p1));
	dfs(kk0,kk1,pp0,pp1);
	return true;
}

void dfs(int k0, int k1, int p0, int p1){
	vis[k0][k1][p0][p1]=true;
	if(k0==3||k1==3)return;
	int g=25;
	if(k0+k1==4)g=15;
	for(int i=0;;++i){
		int gg=max(i+2,g);
		bool a=asd(k0,k1,p0,p1,k0+1,k1,p0+gg,p1+i);
		bool b=asd(k0,k1,p0,p1,k0,k1+1,p0+i,p1+gg);
		if(!a&&!b)break;
	}
}

int main(){
	dfs(0,0,0,0);
	int tn;
	scanf("%d",&tn);
	while(tn--){
		int a,b;
		scanf("%d%d",&a,&b);
		int k0=-1,k1=-1;
		fore(i,0,3)if(vis[3][i][a][b]){k0=3;k1=i;break;}
		if(k0<0){
			for(int i=2;i>=0;--i)if(vis[i][3][a][b]){k0=i;k1=3;break;}
		}
		if(k0<0)puts("Impossible");
		else {
			printf("%d:%d\n",k0,k1);
			vector<pair<int,int> > r;
			while(k0||k1){
				auto p=f[k0][k1][a][b];
				r.pb(mp(a-p.snd.fst,b-p.snd.snd));
				k0=p.fst.fst;k1=p.fst.snd;a=p.snd.fst;b=p.snd.snd;
			}
			reverse(r.begin(),r.end());
			fore(i,0,SZ(r))printf("%d:%d%c",r[i].fst,r[i].snd," \n"[i==SZ(r)-1]);
		}
	}
	return 0;
}