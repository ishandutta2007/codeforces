//I'm submitting the same code for the third time
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
vector<int> divs[2000005];
int mo[2000005];
ll pwn[2000005];
int tw[2000005];
ll power(ll bs,int t){
	ll ans=1LL;
	while(t){
		if(t&1)ans=ans*bs%INF;
		bs=bs*bs%INF;
		t>>=1;
	}
	return ans;
}
void pw_init(int n){
	pwn[0]=0;
	rep1(k,2000000)pwn[k]=power(k,n);
}
void div_init(){
	mo[1]=1;
	for(int i=1;i<=2000000;i++)for(int j=i;j<=2000000;j+=i)divs[j].push_back(i);
	for(int i=1;i<=2000000;i++)for(int j=i+i;j<=2000000;j+=i)mo[j]-=mo[i];
}
ll ans;
void getnew(int cur){
	for(auto num:divs[cur])tw[num]++;
	for(auto num:divs[cur])ans+=mo[num]?(mo[num]>0?pwn[tw[num]]-pwn[tw[num]-1]:pwn[tw[num]-1]-pwn[tw[num]]):0;
	ans%=INF;
	if(ans<0)ans+=INF;
}
int main(){
	int n,p;
	ll ca=0LL;
	scanf("%d%d",&n,&p);
	pw_init(n);
	div_init();
	rep1(k,p){
		getnew(k);
		ca+=(int(ans)^k);
	}
	printf("%I64d\n",ca%INF);
	return 0;
}