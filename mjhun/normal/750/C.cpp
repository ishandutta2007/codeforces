#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define INF (1<<30)
using namespace std;
typedef long long ll;

int s,e,q,n;

int main(){
	scanf("%d",&n);
	s=-INF;e=INF;q=0;
	fore(_,0,n){
		int c,d;
		scanf("%d%d",&c,&d);
		if(d==1)s=max(s,1900-q);
		else e=min(e,1899-q);
		q+=c;
	}
	if(s>e)puts("Impossible");
	else if(e==INF)puts("Infinity");
	else printf("%d\n",e+q);
	return 0;
}