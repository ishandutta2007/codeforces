#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,k;
int x[100005];
pair<int,int> xx[100005];
int g[100005];
int c[100005];
set<int> w;

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n){
		scanf("%d",&xx[i].fst);
		xx[i].snd=i;
	}
	sort(xx,xx+n);
	reverse(xx,xx+n);
	int cur=0;
	fore(i,0,n){
		if(i>0&&xx[i].fst!=xx[i-1].fst)cur++;
		x[xx[i].snd]=cur;
		g[cur]=xx[i].fst;
	}
	fore(i,0,k){
		c[x[i]]++;
		if(c[x[i]]==1)w.insert(x[i]);
		else if(c[x[i]]==2)w.erase(x[i]);
	}
	if(w.empty())puts("Nothing");
	else printf("%d\n",g[*w.begin()]);
	fore(i,k,n){
		c[x[i-k]]--;
		if(c[x[i-k]]==1)w.insert(x[i-k]);
		else if(c[x[i-k]]==0)w.erase(x[i-k]);
		c[x[i]]++;
		if(c[x[i]]==1)w.insert(x[i]);
		else if(c[x[i]]==2)w.erase(x[i]);
		if(w.empty())puts("Nothing");
		else printf("%d\n",g[*w.begin()]);
	}
	return 0;
}