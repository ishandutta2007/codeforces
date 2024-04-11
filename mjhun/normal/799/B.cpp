#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

multiset<pair<int,int> > w[8];
int n,m;
int p[200005],a[200005],b[200005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",p+i);
	fore(i,0,n)scanf("%d",a+i),a[i]--;
	fore(i,0,n)scanf("%d",b+i),b[i]--;
	fore(i,0,n)w[a[i]].insert(mp(p[i],b[i])),w[b[i]].insert(mp(p[i],a[i]));
	scanf("%d",&m);
	fore(i,0,m){
		if(i)putchar(' ');
		int c;
		scanf("%d",&c);c--;
		if(w[c].empty())printf("-1");
		else {
			auto p=*w[c].begin();
			printf("%d",p.fst);
			auto q=mp(p.fst,c);
			w[p.snd].erase(w[p.snd].find(q));
			w[c].erase(w[c].find(p));
		}
	}
	puts("");
	return 0;
}