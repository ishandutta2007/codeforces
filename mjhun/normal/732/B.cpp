#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,k;
int x[512];

int main(){
	scanf("%d%d",&n,&k);
	fore(i,1,n+1)scanf("%d",x+i);
	x[0]=x[n+1]=k;
	int r=0;
	fore(i,1,n+1){
		if(x[i]+x[i-1]<k){
			r+=k-x[i]-x[i-1];
			x[i]+=k-x[i]-x[i-1];
		}
	}
	printf("%d\n",r);
	fore(i,1,n+1){
		if(i>1)putchar(' ');
		printf("%d",x[i]);
	}
	puts("");
	return 0;
}