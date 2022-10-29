#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

int h[1024];
int f0[200005];
int f1[200005];
int r,g;

int main(){
	fore(i,1,1024)h[i]=h[i-1]+i;
	scanf("%d%d",&r,&g);
	if(!r||!g){puts("1");return 0;}
	f0[0]=f0[1]=1;
	fore(k,1,1024){
		fore(g0,0,g+1){
			int r0=h[k]-g0;
			if(r0<0||r0>r)f1[g0]=0;
			else {
				f1[g0]=0;
				if(r0>=k)f1[g0]+=f0[g0];
				if(g0>=k)f1[g0]+=f0[g0-k],f1[g0]%=MOD;
			}
		}
		bool end=true;
		fore(i,0,g+1)if(f1[i]>0)end=false;
		if(end){
			int s=0;
			fore(i,0,g+1){
				s+=f0[i];
				s%=MOD;
			}
			printf("%d\n",s);
			return 0;
		}
		memcpy(f0,f1,sizeof(f0));
	}
	assert(0);
	//puts("demetrio");
	return 0;
}