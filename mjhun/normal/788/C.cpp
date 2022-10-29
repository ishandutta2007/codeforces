#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

/*
vector<pair<int,ll> > g[1024];
ll d[1024];

void dijkstra(){
	memset(d,-1,sizeof(d))
}
*/

const int N=(1<<20);

bool e[1024];
int a[1024];
bitset<N> w;
bitset<N> w1;
int n,k;

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,k){
		int x;
		scanf("%d",&x);
		e[x]=true;
	}
	k=0;
	fore(i,0,1024)if(e[i])a[k++]=i;
	if(n<a[0]||n>a[k-1]){puts("-1");return 0;}
	fore(i,0,k)w[a[i]]=1;
	int r=1;
	while(!w[r*n]){
		w1.reset();
		fore(i,0,k)w1|=w<<a[i];
		w=w1;
		r++;
	}
	printf("%d\n",r);
	return 0;
}