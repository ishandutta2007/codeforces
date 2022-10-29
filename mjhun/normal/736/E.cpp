#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

void perdi(){puts("no");exit(0);}

int n,m;
int s[3003];
char r[3003][3003];
int t;
set<pair<int,int> > w;

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,m)scanf("%d",s+i),t+=s[i];
	if(t>n*(n-1))perdi();
	if(m==n&&t!=n*(n-1))perdi();
	if(m<n){
		int z=n*(n-1)-t;
		fore(i,m,n){
			s[i]=z/(n-m);
			if(i-m<z%(n-m))s[i]++;
		}
		if(s[m]>s[m-1])perdi();
	}
	fore(i,0,n){
		fore(j,0,n)r[i][j]='D';
		r[i][i]='X';
	}
	fore(i,0,n)w.insert(mp(s[i]-(n-1),i));
	while(!w.empty()){
		auto p=*w.rbegin();
		w.erase(p);
		assert(p.fst>=0);
		if(p.fst>w.size())perdi();
		vector<pair<int,int> > v;
		fore(_,0,p.fst){
			auto q=*w.begin();
			w.erase(w.begin());
			r[p.snd][q.snd]='W';
			r[q.snd][p.snd]='L';
			q.fst++;
			v.pb(q);
		}
		for(auto q:v)w.insert(q);
	}
	puts("yes");
	fore(i,0,n)puts(r[i]);
	return 0;
}