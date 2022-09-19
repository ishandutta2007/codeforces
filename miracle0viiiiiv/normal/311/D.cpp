#pragma comment(linker, "/stack:200000000")
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
const int MOD=95542721;
const int BUCKET=6; //the best size
ll dat[100005],ans[100005][50];
int tms[100005];
void realise(int buc,int cl,int cr){
	for(int i=cl;i<=cr;i++){
		ll ci=dat[i];
		for(int j=0;j<48;j++){
			ans[buc][j]-=ci;
			if(ans[buc][j]<0)ans[buc][j]+=MOD;
			ci=ci*ci%MOD*ci%MOD;
		}
	}
	for(int i=cl;i<=cr;i++){
		dat[i]=dat[i]*dat[i]%MOD*dat[i]%MOD;
		ll ci=dat[i];
		for(int j=0;j<48;j++){
			ans[buc][j]+=ci;
			if(ans[buc][j]>=MOD)ans[buc][j]-=MOD; 
			ci=ci*ci%MOD*ci%MOD;
		}
	}
}
void modify(int l,int r){
	int lb=l/BUCKET,rb=r/BUCKET;
	if(lb==rb)realise(lb,l,r);
	else{
		realise(lb,l,lb*BUCKET+BUCKET-1);
		realise(rb,rb*BUCKET,r);
		for(int k=lb+1;k<rb;k++){
			tms[k]++;
			if(tms[k]>=48)tms[k]-=48;
		}
	}
}
ll brute(int buc,int cl,int cr){
	ll res=0LL;
	for(int i=cl;i<=cr;i++){
		ll ci=dat[i];
		rep(j,tms[buc])ci=ci*ci%MOD*ci%MOD;
		res+=ci;
	}
	return res%MOD;
}
ll query(int l,int r){
	int lb=l/BUCKET,rb=r/BUCKET;
	ll res=0LL;
	if(lb==rb)res=brute(lb,l,r);
	else{
		res=brute(lb,l,lb*BUCKET+BUCKET-1)+brute(rb,rb*BUCKET,r);
		for(int k=lb+1;k<rb;k++)res+=ans[k][tms[k]];
	}
	res%=MOD;
	if(res<0)res+=MOD;
	return res;
}
int main(){
	int n,q,t,l,r;
	scanf("%d",&n);
	rep(k,n)scanf("%I64d",&dat[k]);
	rep(i,n){
		int buc=i/BUCKET;
		ll ci=dat[i];
		rep(j,48){
			ans[buc][j]+=ci;
			if(ans[buc][j]>=MOD)ans[buc][j]-=MOD;
			ci=ci*ci%MOD*ci%MOD;
		}
	}
	scanf("%d",&q);
	rep(k,q){
		scanf("%d%d%d",&t,&l,&r);l--;r--;
		if(t==1)printf("%I64d\n",query(l,r));
		else modify(l,r);
	}
	return 0;
}