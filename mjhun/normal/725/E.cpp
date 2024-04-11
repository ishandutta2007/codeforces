#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int m,n;
int x[200005];
int w[200005];

bool gane(int q){
	int k=n,j=n;
	bool u=false;
	if(!q)u=true;
	while(j>0){
		if(!w[j]){
			if(u||q>k)break;
			u=true;
			k-=q;
		}
		else {
			if(!u&&q<=k&&q>=w[j]){
				u=true;
				k-=q;
			}
			else {
				j=w[j];
				k-=min(k/j,x[j])*j;
				j--;
			}
		}
		j=min(j,k);
	}
	return k!=0;
}

int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int k;
		scanf("%d",&k);
		x[k]++;
	}
	int l=0;
	fore(i,1,n+1){
		if(x[i])l=i;
		w[i]=l;
	}
	fore(i,0,n){
		if(gane(i)){printf("%d\n",i);return 0;}
	}
	puts("Greed is good");
	return 0;
}