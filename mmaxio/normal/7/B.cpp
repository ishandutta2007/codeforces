#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;
                                       
map<int, pair<int,int> > mem;//start - ident, size

int t, m, cur_id = 0;

void _alloc(int x) {
	//cerr << "alloc " << x << '\n';
	
	if (x>m) {
		printf("NULL\n");
		return;
	}
	if (mem.empty() || mem.begin()->fs > x) {
		cur_id++;
		mem[1] = mp(cur_id,x);
		printf("%d\n",cur_id);
		return;
	}

	for (map<int, pair<int,int> >::iterator it = mem.begin(); it!=mem.end(); it++) {
		int can_en;
		map<int, pair<int,int> >::iterator it1 = it; it1++;
		if (it1==mem.end()) can_en = m; else can_en = (it1->fs - 1);
		int can_st = it->fs+it->sc.sc;
		//if (x==3) cerr << can_st << ' ' << can_en << '\n';
		if (can_en-can_st+1>=x) {
			cur_id++;
			mem[can_st] = mp(cur_id,x);
			printf("%d\n",cur_id);
			return;
		}
	}

	printf("NULL\n");

}

void _erase(int x) {
   	//cerr << "erase " << x << '\n';
	for (map<int, pair<int,int> >::iterator it = mem.begin(); it!=mem.end(); it++) if (it->sc.fs == x) {
		mem.erase(it);
		return;
	}
	printf("ILLEGAL_ERASE_ARGUMENT\n");

}

void _defrag() {
	//cerr << "defrag " << '\n';
	map<int, pair<int,int> > tmp;//start - ident, size
	int fr = 1;
	for (map<int, pair<int,int> >::iterator it = mem.begin(); it!=mem.end(); it++) {
		tmp[fr] = it->sc;
		fr = fr+it->sc.sc;
	}
	mem = tmp;
	
	//for (map<int, pair<int,int> >::iterator it = mem.begin(); it!=mem.end(); it++) cerr << it->fs << " - " << it->sc.sc << ' ' << it->sc.fs << '\n';
}


int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d %d\n",&t,&m);
	int x; string s;
	REP(i,t) {
		char c = gch;
		if (c=='a') {
			while ((c=gch)>='a' && c<='z');
			scanf("%d\n",&x);
			_alloc(x);
		} else if (c=='e') {
			while ((c=gch)>='a' && c<='z');
			scanf("%d\n",&x);
			_erase(x);

		} else {
		    while ((c=gch)>='a' && c<='z');
			_defrag();
		}
		//for (map<int, pair<int,int> >::iterator it = mem.begin(); it!=mem.end(); it++) cerr << it->fs << " - " << it->sc.sc << ' ' << it->sc.fs << ' '; cerr << '\n';
	}

}