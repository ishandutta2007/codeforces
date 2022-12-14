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

#define MAXN 100007
int tell[MAXN], yes[MAXN], no[MAXN], YES, NO, n, m, how;
bool sus[MAXN];

int main(){ 
	//in
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",&tell[i]);
	//sol
	FOR(i,1,n)
		if(tell[i] > 0) {
			yes[tell[i]]++;
			YES++;
		} else {
			no[-tell[i]]++;
			NO++;
		}
	FOR(i,1,n)
		how += (sus[i] = (NO - no[i] + yes[i] == m));
	//out
	FOR(i,1,n)
		if(tell[i] > 0){
			if(!sus[tell[i]])
				printf("Lie\n");
			else if(how>1)
				printf("Not defined\n");
			else
				printf("Truth\n");
		} else {
			if(!sus[-tell[i]])
				printf("Truth\n");
			else if(how>1)
				printf("Not defined\n");
			else
				printf("Lie\n");
		}
    return 0;
}