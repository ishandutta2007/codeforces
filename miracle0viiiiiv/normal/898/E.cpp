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
vector<int> cost1,cost2;
int sqr[33000];
int main(){
	rep(k,32767)sqr[k]=k*k;
	int n,x,cnt=0;
	scanf("%d",&n);
	rep(k,n){
		scanf("%d",&x);
		int pos=lower_bound(sqr,sqr+32767,x)-sqr;
		if(sqr[pos]==x){
			cost2.push_back(x==0?2:1);
			cnt++;
		}else cost1.push_back(min(sqr[pos]-x,x-sqr[pos-1]));
	}
	sort(cost1.begin(),cost1.end());
	sort(cost2.begin(),cost2.end());
	ll ans=0LL;
	if(cnt+cnt<=n){
		int nn=n/2-cnt;
		rep(k,nn)ans+=cost1[k];
	}else{
		int nn=cnt-n/2;
		rep(k,nn)ans+=cost2[k];
	}
	printf("%I64d\n",ans);
	return 0;
}