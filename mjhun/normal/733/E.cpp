#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,nd,nu;
char s[1<<20];
int cu[1<<20];
ll sd[1<<20];
ll su[1<<20];
int ld[1<<20];
int lu[1<<20];

int main(){
	scanf("%d%s",&n,s);
	fore(i,0,n){
		ld[i]=nd-1;
		lu[i]=nu-1;
		cu[i+1]=cu[i];
		if(s[i]=='U'){
			cu[i+1]++;
			su[nu+1]=su[nu]+i;
			nu++;
		}
		else {
			sd[nd+1]=sd[nd]+i;
			nd++;
		}
	}
	ld[n]=nd-1;
	lu[n]=nu-1;
	fore(i,0,n){
		ll r;
		int ui,dd;
		ui=cu[i];
		dd=n-1-i-(cu[n]-cu[i+1]);
		if(s[i]=='U'){
			if(dd<=ui){
				// me voy por la derecha
				r=2*((sd[nd]-sd[nd-dd])-1LL*(dd)*i);
				r+=n-i;
				int k=lu[i];
				r+=2*(1LL*dd*i-(su[k+1]-su[k+1-dd]));
			}
			else {
				// ui<dd
				// me voy por la izquierda
				r=2*(1LL*(ui)*i-(su[ui]-su[0]));
				r+=i+1;
				int k=ld[i]+1;
				r+=2*((sd[k+ui+1]-sd[k])-1LL*(ui+1)*i);
			}
		}
		else {
			if(ui<=dd){
				// me voy por la izquierda
				r=2*(1LL*(ui)*i-(su[ui]-su[0]));
				r+=i+1;
				int k=ld[i+1]+1;
				r+=2*((sd[k+ui]-sd[k])-1LL*ui*i);
			}
			else {
				// dd<ui
				// me voy por la derecha
				r=2*((sd[nd]-sd[nd-dd])-1LL*(dd)*i);
				r+=n-i;
				int k=lu[i];
				r+=2*(1LL*(dd+1)*i-(su[k+1]-su[k+1-dd-1]));
			}
		}
		if(i)putchar(' ');
		printf("%lld",r);
	}
	puts("");
	return 0;
}