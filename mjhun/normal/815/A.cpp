#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

void perdi(){puts("-1");exit(0);}

int n,m;
int b[128][128];
vector<pair<int,int> > r;
int qr[128],qc[128];

void dor(int i){
	fore(j,0,m)if(b[i][j]){
		fore(_,0,b[i][j])r.pb(mp(1,j));
		int k=b[i][j];
		fore(i0,0,n){
			if(b[i0][j]<k)perdi();
			b[i0][j]-=k;
			if(!b[i0][j])qr[i0]--,qc[j]--;
		}
		return;
	}
	assert(0);
}

void doc(int j){
	fore(i,0,n)if(b[i][j]){
		fore(_,0,b[i][j])r.pb(mp(0,i));
		int k=b[i][j];
		fore(j0,0,m){
			if(b[i][j0]<k)perdi();
			b[i][j0]-=k;
			if(!b[i][j0])qr[i]--,qc[j0]--;
		}
		return;
	}
	assert(0);
}

int main(){
	scanf("%d%d",&n,&m);
	int mn=1<<30;
	fore(i,0,n)fore(j,0,m)scanf("%d",&b[i][j]),mn=min(mn,b[i][j]);
	fore(_,0,mn){
		if(n<m)fore(i,0,n)r.pb(mp(0,i));
		else fore(i,0,m)r.pb(mp(1,i));
	}
	fore(i,0,n)fore(j,0,m)b[i][j]-=mn;
	fore(i,0,n)fore(j,0,m){
		if(b[i][j])qr[i]++,qc[j]++;
	}
	while(1){
		bool asd=false;
		fore(i,0,n)if(qr[i]&&qr[i]<m){
			asd=true;
			dor(i);
			break;
		}
		if(!asd)fore(j,0,m)if(qc[j]&&qc[j]<n){
			asd=true;
			doc(j);
			break;
		}
		if(!asd)break;
	}
	printf("%d\n",(int)r.size());
	for(auto p:r){
		if(p.fst==0)printf("row %d\n",p.snd+1);
		else printf("col %d\n",p.snd+1);
	}
	return 0;
}