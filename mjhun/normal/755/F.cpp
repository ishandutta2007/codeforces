#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,m;
int p[1<<20],c[1<<20];
bool v[1<<20];
bitset<1<<20> w;
int f[1<<20];

int solve1(){
	w[0]=1;
	fore(i,150,n+1)fore(_,0,c[i])w|=w<<i;
	fore(i,1,150){
		if(!c[i])continue;
		fore(j,0,n+1){
			if(w[j])f[j]=0;
			else if(j>=i&&f[j-i]<c[i]){
				f[j]=f[j-i]+1;
				w[j]=1;
			}
			else f[j]=1<<20;
		}
	}
	if(w[m])return m;
	return m+1;
}

int solve2(){
	int a=m,r=0;
	fore(i,1,n+1)fore(_,0,c[i]){
		int k=min(i/2,a);
		r+=2*k;
		a-=k;
	}
	for(int i=1;i<=n;i+=2)fore(_,0,c[i])if(a)a--,r++;
	return r;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%d",p+i),p[i]--;
	fore(i,0,n)if(!v[i]){
		int k=0;
		while(!v[i]){
			v[i]=true;
			k++;
			i=p[i];
		}
		c[k]++;
	}
	printf("%d %d\n",solve1(),solve2());
	return 0;
}