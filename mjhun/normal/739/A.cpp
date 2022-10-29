#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int n,m;
int x[100005];
int y[100005];

int main(){
	scanf("%d%d",&n,&m);
	int r=100005;
	fore(i,0,m)scanf("%d%d",x+i,y+i),r=min(r,y[i]-x[i]+1);
	printf("%d\n",r);
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",i%r);
	}
	puts("");
	return 0;
}