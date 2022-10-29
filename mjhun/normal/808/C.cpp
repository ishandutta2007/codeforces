#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,w;
pair<int,int> z[128];
int r[128],rr[128];

int main(){
	scanf("%d%d",&n,&w);
	fore(i,0,n){
		int a;
		scanf("%d",&a);
		z[i]=mp(a,i);
	}
	sort(z,z+n);
	int s=0;
	fore(i,0,n){
		r[i]=(z[i].fst+1)/2;
		s+=r[i];
	}
	if(s>w){puts("-1");return 0;}
	int k=n-1;
	fore(_,s,w){
		if(r[k]==z[k].fst)k--;
		r[k]++;
	}
	fore(i,0,n)rr[z[i].snd]=r[i];
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",rr[i]);
	}
	puts("");
	return 0;
}