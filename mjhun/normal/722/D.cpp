#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n;
/*
int nt;
int t[1<<21][2];
int q[1<<21];
bool f[1<<21];

vector<int> sol;

void tadd(int x){
	int s=0;
	fore(i,0,32)if((x>>i)&1)s=i;
	int k=0;
	//s=31;
	q[0]++;
	for(int i=s;i>=0;--i){
		int d=(x>>i)&1;
		printf(" %d",d);
		if(t[k][d]<0)t[k][d]=nt++;
		k=t[k][d];
		q[k]++;
	}
	f[k]=true;
	puts("");
}

void dfs(int x, int w, int v){
	printf("%d %d %d\n",q[x],w,v);
	assert(w<q[x]);
	if(v){
		sol.pb(v);
		if(!f[x])w++;
	}
	int w0,w1;
	if(t[x][0]<0&&t[x][1]<0)return;
	else if(t[x][0]<0){
		if(w<q[t[x][1]])dfs(t[x][1],w,2*v+1);
	}
	else if(t[x][1]<0){
		if(w<q[t[x][0]])dfs(t[x][0],w,2*v);
	}
	else {
		printf("a %d %d\n",v,q[t[x][1]]);
		w1=min(w,q[t[x][1]]);
		w0=w-w1;
		printf("  %d %d\n",w1,q[t[x][1]]);
		if(w1<q[t[x][1]])dfs(t[x][1],w1,2*v+1);
		if(w0<q[t[x][0]])dfs(t[x][0],w0,2*v);
	}
}


int w[1<<21];
int v[1<<21];
*/

set<int> ys;

int main(){
	/*nt=1;
	memset(t,-1,sizeof(t));
	*/
	scanf("%d",&n);
	fore(i,0,n){
		int y;
		scanf("%d",&y);
		ys.insert(-y);
		//tadd(y);
	}
	//assert(t[0][0]==-1&&t[0][1]==1);
	/*w[1]=0;
	v[1]=1;
	q.push(1);
	while(!q.empty()){

	}*/
	while(1){
		int x=-(*ys.begin());
		int w=x;
		while(w&&ys.count(-w)){
			w/=2;
		}
		if(!w)break;
		ys.erase(-x);
		ys.insert(-w);
	}
	bool p=false;
	for(set<int>::iterator it=ys.begin();it!=ys.end();++it){
		if(p)putchar(' ');
		printf("%d",-(*it));
		p=true;
	}
	puts("");
//	dfs(0,0,0);
//	printf("%d",sol[0]);
//	fore(i,1,n)printf(" %d",sol[i]);puts("");
	return 0;
}