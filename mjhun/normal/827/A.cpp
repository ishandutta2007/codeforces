#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,m;
string s[100005];
char _s[1<<21];
vector<pair<int,int> > e;
char r[1<<21];
set<pair<int,int> > l;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%s",_s);
		s[i]=string(_s);
		int k;
		scanf("%d",&k);
		while(k--){
			int x;
			scanf("%d",&x);x--;
			m=max(m,x+(int)s[i].size());
			e.pb(mp(x,i));
			e.pb(mp(x+s[i].size(),-i-1));
		}
	}
	fore(i,0,m)e.pb(mp(i,1<<20));
	sort(e.begin(),e.end());
	for(auto p:e){
		if(p.snd!=(1<<20)&&p.snd>=0){
			int i=p.snd;
			l.insert(mp(i,p.fst));
		}
		else if(p.snd<0){
			int i=-p.snd-1;
			l.erase(mp(i,p.fst-s[i].size()));
		}
		else {
			if(!l.empty()){
				r[p.fst]=s[l.begin()->fst][p.fst-l.begin()->snd];
			}
			else r[p.fst]='a';
		}
	}
	puts(r);
	return 0;
}