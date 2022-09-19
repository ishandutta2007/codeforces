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
int arr[200005],cc[200005];
set<int> hv;
int main(){
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	rep(k,n)cc[k]=1;
	rep(k,n)scanf("%d",&arr[k]);
	sort(arr,arr+n);
	int l=0,cur=0,ans=0;
	rep(k,n){
		cur+=cc[k];
		hv.insert(k);
		while(arr[k]-arr[l]>=m){
			cur-=cc[l];
			l++;
		}
		if(cur>=t){
			int out=*hv.rbegin();
			cc[out]=0;
			cur--;
			hv.erase(hv.find(out));
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}