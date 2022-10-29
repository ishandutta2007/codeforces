#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

pair<pair<int,int>,int> x[100005];
int n;
ll sa,sb;
int as[100005],bs[100005];

bool valid(){
	ll a=0,b=0;
	fore(i,0,n/2+1)a+=x[i].fst.fst,b+=x[i].fst.snd;
	return 2*a>sa&&2*b>sb;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",as+i),sa+=as[i];
	fore(i,0,n)scanf("%d",bs+i),sb+=bs[i];
	fore(i,0,n)x[i]=mp(mp(as[i],bs[i]),i);
	while(!valid())random_shuffle(x,x+n);
	printf("%d\n",n/2+1);
	fore(i,0,n/2+1){
		if(i)putchar(' ');
		printf("%d",x[i].snd+1);
	}
	puts("");
	return 0;
}