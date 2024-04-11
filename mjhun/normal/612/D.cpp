#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

pair<int,int> x[1<<21];
vector<pair<int,int> > sol;
int n,k;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i){
		int w;
		scanf("%d",&w);
		x[i]=mp(w,0);
		scanf("%d",&w);
		x[n+i]=mp(w,1);
	}
	sort(x,x+2*n);
	int q=0,s;
	for(int i=0;i<2*n;++i){
		int w=x[i].fst;
		if(x[i].snd){
			if(q==k)sol.push_back(mp(s,w));
			q--;
		}
		else {
			q++;
			if(q==k)s=w;
		}
	}
	printf("%d\n",sol.size());
	for(int i=0;i<sol.size();++i){
		printf("%d %d\n",sol[i].fst,sol[i].snd);
	}
	return 0;
}