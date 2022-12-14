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

#define MAXN 200007
#define LET ('z'-'a'+1)

struct DP{
int tab[MAXN];
DP(){CLR(tab,0); FOR(i,1,MAXN-1) add(i,1);}
void add(int x,int w){
while(x<MAXN){tab[x]+=w; x+=(x&(-x));}
}
int get(int x){
int wyn=0;
while(x){wyn+=tab[x]; x-=(x&(-x));}
return wyn;
}
int get(int a,int b){return get(b)-get(a-1);}
int one(int x){return get(x)-get(x-1);}
void find(int x) {
	int l = 0, r = MAXN - 1;
	while(r>l){
		int q=(l+r)/2;
		if(get(q) >= x)
			r=q;
		else
			l=q+1;
	}
//	cout << "find " << x << " = " << l << endl;
	add(l,-1);
}
};

DP dp[LET];
char c[107],y[7],res[MAXN];
int k,n,x,poz,ile[LET];

int main(){ 
	//in
	scanf("%d%s%d",&k,c,&n);
	//sol
	while(n--){
		scanf("%d%s",&x,y);
		int p = y[0]-(int)'a';
		dp[p].find(x);
	}
	//out
	REP(q,k) for(int i=0;c[i];i++){
		int p = c[i]-(int)'a';
		if(dp[p].one(++ile[p]))
			res[poz++] = c[i];
	}
	res[poz++] = 0;
	printf("%s\n", res);
    return 0;
}