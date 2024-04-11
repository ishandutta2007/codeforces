#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n;

pair<int,pair<int,int> > r;
map<pair<int,int>,pair<int,int> > w;

int min3(int a, int b, int c){
	return min(a,min(b,c));
}

int main(){
	scanf("%d",&n);
	r.fst=-1;
	fore(i,0,n){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		vector<int> v;v.clear();
		v.pb(a);v.pb(b);v.pb(c);
		sort(v.begin(),v.end());
		r=max(r,mp(v[0],mp(i,-1)));
		if(w.count(mp(v[0],v[1]))){
			int k=w[mp(v[0],v[1])].fst;
			int j=w[mp(v[0],v[1])].snd;
			r=max(r,mp(min3(v[0],v[1],k+v[2]),mp(j,i)));
		}
		if(w.count(mp(v[0],v[2]))){
			int k=w[mp(v[0],v[2])].fst;
			int j=w[mp(v[0],v[2])].snd;
			r=max(r,mp(min3(v[0],v[2],k+v[1]),mp(j,i)));
		}
		if(w.count(mp(v[1],v[2]))){
			int k=w[mp(v[1],v[2])].fst;
			int j=w[mp(v[1],v[2])].snd;
			r=max(r,mp(min3(v[1],v[2],k+v[0]),mp(j,i)));
		}
		w[mp(v[0],v[1])]=max(w[mp(v[0],v[1])],mp(v[2],i));
		w[mp(v[0],v[2])]=max(w[mp(v[0],v[2])],mp(v[1],i));
		w[mp(v[1],v[2])]=max(w[mp(v[1],v[2])],mp(v[0],i));
	}
	if(r.snd.snd<0)printf("1\n%d\n",r.snd.fst+1);
	else printf("2\n%d %d\n",r.snd.fst+1,r.snd.snd+1);
	return 0;
}