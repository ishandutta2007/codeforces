#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,m;
vector<int> g[100005];
int d[100005];
int r[100005];

priority_queue<int> q;

int main(){
	scanf("%d%d",&n,&m);
	fore(_,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[y].pb(x);
		d[x]++;
	}
	fore(i,0,n)if(d[i]==0)q.push(i);
	int k=n;
	while(!q.empty()){
		int x=q.top();q.pop();
		r[x]=k--;
		for(int y:g[x]){
			d[y]--;
			if(d[y]==0)q.push(y);
		}
	}
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",r[i]);
	}
	puts("");
	return 0;
}