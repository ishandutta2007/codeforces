#include <cstdio>
#include <iostream>
#include <set>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

int n,q;
set<pair<pair<int,int>,pair<int,int> > > w;


int main(){
	scanf("%d %d",&n,&q);
	w.insert(mp(mp(1,n),mp(1,n)));
	while(q--){
		int x,y;char c;
		scanf("%d %d %c",&x,&y,&c);
		set<pair<pair<int,int>,pair<int,int> > >::iterator it;
		it=w.lower_bound(mp(mp(x+1,0),mp(0,0)));
		if(it==w.begin()){
			puts("0");
			continue;
		}
		it--;
		if(it->fst.fst>x||it->fst.snd<x){
			puts("0");
			continue;
		}
		int a=it->fst.fst,b=it->fst.snd,u=it->snd.fst,l=it->snd.snd;
		w.erase(it);
		if(c=='U'){
			printf("%d\n",u+b-x);
			if(a<=x-1)w.insert(mp(mp(a,x-1),mp(u+b-x+1,l+x-b-1)));
			if(x+1<=b)w.insert(mp(mp(x+1,b),mp(u,b-x)));
		}
		else {
			printf("%d\n",l+x-b);
			if(a<=x-1)w.insert(mp(mp(a,x-1),mp(1,l+x-b-1)));
			if(x+1<=b)w.insert(mp(mp(x+1,b),mp(u,l)));
		}
	}
	return 0;
}