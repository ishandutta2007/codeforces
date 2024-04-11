#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

vector<pair<int,int> > w;

int n,q;
int x[200005];
int c[200005];

int main(){
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;++i)scanf("%d",x+i);
	while(q--){
		int s,e;
		scanf("%d%d",&s,&e);
		w.push_back(mp(s-1,1));
		w.push_back(mp(e,-1));
	}
	sort(w.begin(),w.end());
	int k=0,r=0;
	for(int i=0;i<n;++i){
		while(k<w.size()&&w[k].fst==i)r+=w[k].snd,k++;
		c[i]=r;
	}
	sort(x,x+n);
	sort(c,c+n);
	long long a=0;
	for(int i=0;i<n;++i){
		a+=1LL*x[i]*c[i];
	}
	cout<<a<<endl;
	return 0;
}