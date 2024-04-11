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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

string f[1000];
set<string> q;

string shift(string s) {
	char c = s[0];
	REP(i, 3) s[i] = s[i + 1];
	s[3] = c;
	return s;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n;                             
	scanf("%d\n",&n);
	REP(i, n) f[i] = string(4, 'x');
	REP(i, n) {
		f[i][0] = gch;
		f[i][1] = gch;
		gch;
		f[i][3] = gch;
		f[i][2] = gch;
		gch;
		REP(tmp, 3) gch;

		//cerr << f[i] << '\n';

	}
	int ans= 0;
	REP(i, n) {
		string p[4];
		p[0] = f[i];
		FORD(j, 1, 3) p[j] = shift(p[j - 1]);
		//REP(j, 4) cerr << p[j] << '\n';
		//cerr << '\n';
		bool add = true;
		REP(j, 4) if (q.find(p[j]) != q.end()) add = false;
		if (add) ans++;
		REP(j, 4) q.insert(p[j]);
	}
	printf("%d",ans);

}