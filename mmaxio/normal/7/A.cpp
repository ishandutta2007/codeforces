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

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

string s[8];

int main() {
/*	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif*/
	REP(i,8) getline(cin,s[i]);
	int bl = 0;
	REP(i,8) REP(j,8) if (s[i][j]=='B') bl++;
	if (bl==64) {
		printf("8\n");
		return 0;
	}
	int ans = 0;
	REP(i,8) {
		bool good = 1;
		REP(j,8) if (s[i][j]=='W') good = 0;
		if (good) ans++;
	}
	REP(i,8) {
		bool good = 1;
		REP(j,8) if (s[j][i]=='W') good = 0;
		if (good) ans++;
	}
	printf("%d\n",ans);
}