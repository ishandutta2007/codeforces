#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
int can[405][405],dist[405];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(k,m){
		int u,v;
		scanf("%d%d",&u,&v);
		can[u][v]=can[v][u]=1;
	}
	int sat=!can[1][n];
	rep1(k,n)dist[k]=-1;
	queue<int> Q;
	Q.push(1);
	dist[1]=0;
	while(!Q.empty()){
		int v=Q.front();Q.pop();
		rep1(k,n)if(can[v][k]==sat&&dist[k]==-1){
			Q.push(k);
			dist[k]=dist[v]+1;
		}
	}
	printf("%d\n",dist[n]);
	return 0;
}