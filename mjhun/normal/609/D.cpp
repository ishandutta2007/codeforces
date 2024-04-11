#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

int n,m,k,s;
int p[2][200005];
int p2[2][200005];
vector<pair<int,int> > w[2];
vector<pair<int,int> > sol;

bool can(int l){
	sol.clear();
	int c0=p2[0][p[0][l-1]],c1=p2[1][p[1][l-1]];
	long long t=s;
	int i0=0,i1=0,q=0;
	while(t>=0&&q<k){
		bool g0;
		if(i0>=w[0].size())g0=false;
		else if(i1>=w[1].size())g0=true;
		else g0=1LL*c0*w[0][i0].fst<1LL*c1*w[1][i1].fst;
		if(g0){
			sol.push_back(make_pair(w[0][i0].snd,p[0][l-1]+1));
			t-=1LL*c0*w[0][i0].fst;
			i0++;
		}
		else {
			sol.push_back(make_pair(w[1][i1].snd,p[1][l-1]+1));
			t-=1LL*c1*w[1][i1].fst;
			i1++;
		}
		q++;
	}
	return t>=0&&q==k;
}

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int t=0;t<2;++t){
		for(int i=0;i<n;++i){
			scanf("%d",&p2[t][i]);
		}
		int b=0;
		for(int i=1;i<n;++i){
			if(p2[t][i]<p2[t][b]){
				b=i;
			}
			p[t][i]=b;
		}
	}
	for(int i=0;i<m;++i){
		int t,c;
		scanf("%d%d",&t,&c);
		w[t-1].push_back(mp(c,i+1));
	}
	sort(w[0].begin(),w[0].end());
	sort(w[1].begin(),w[1].end());
	int x=0,y=n+2;
	while(y-x>1){
		int z=(x+y)/2;
		if(!can(z))x=z;
		else y=z;
	}
	int r=x+1;
	if(r>n)puts("-1");
	else {
		can(r);
		printf("%d\n",r);
		for(int i=0;i<k;++i){
			printf("%d %d\n",sol[i].fst,sol[i].snd);
		}
	}
	return 0;
}