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
vector<int> v;
char c[100005];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",c);
	int cur=1;
	for(int k=1;k<n;k++)
	if(c[k]==c[k-1])cur++;
	else{
		v.push_back(cur);
		cur=1;
	}
	v.push_back(cur);
	int cc=0;
	rep(k,v.size())if(v[k]==2)cc++;
	else if(v[k]>2)cc+=2;
	if(cc>=2)printf("%d\n",v.size()+2);
	else if(cc)printf("%d\n",v.size()+1);
	else printf("%d\n",v.size());
	return 0;
}