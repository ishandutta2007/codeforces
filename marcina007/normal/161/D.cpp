#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,w) memset((x),w,sizeof (x))
#define X first
#define Y second
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> VI;

#define MAXN 50007
int n,k,a,b,ile[MAXN][507];
VI kraw[MAXN];
lli res;

void go(int x, int o){
	FORE(i,kraw[x])
		if(*i != o){
			go(*i, x);
			REP(j,k-1)
				ile[x][j+1] += ile[*i][j];
		}
	ile[x][0]=1;
//	REP(j,k) cout << x << " " << j << " = " << ile[x][j] << endl;
	
	FORE(i,kraw[x])
		if(*i != o){
			REP(j,k)
				res += ((lli)ile[*i][j]) * (ile[x][k-1-j]-(k-j-2>=0 ? ile[*i][k-2-j] : 0));
			res += ile[*i][k-1];
		}
//	cout << "res " << res << endl;
}

int main(){ 
	//in
	scanf("%d%d",&n,&k);
	REP(i,n-1) {
		scanf("%d%d",&a,&b);
		kraw[a].PB(b);
		kraw[b].PB(a);
	}
	//sol
	go(1,1);
	//out
	if(res%2) {return -1;}
	cout << res/2 << endl;
    return 0;
}