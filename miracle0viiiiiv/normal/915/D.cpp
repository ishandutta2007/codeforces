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
int cnt[505][505];
bool disa[505][505];
vector<int> G[505];
int vis[505];
vector<int> vec;
int dfs(int v){
	vis[v]=1;
	vec.push_back(v);
	rep(k,G[v].size()){
		int u=G[v][k];
		if(disa[v][u])continue;
		if(!vis[u]){
			int cc=dfs(u);
			if(cc!=-1)return cc;
		}else if(vis[u]==1)return u;
	}
	vis[v]=-1;
	vec.pop_back();
	return -1;
}
int check(int n){
	memset(vis,0,sizeof(vis));
	vec.clear();
	rep1(k,n)if(!vis[k]){
		int cc=dfs(k);
		if(cc!=-1)return cc;
	}
	return -1;
}
int main(){
	int n,m,frm;
	scanf("%d%d",&n,&m);
	rep(k,m){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		cnt[u][v]++;
	}
	if((frm=check(n))==-1)puts("YES");
	else{
		vector<int> cyc=vec;
		rep(k,cyc.size())
		if(cyc[k]==frm){
			cyc.erase(cyc.begin(),cyc.begin()+k);
			break;
		}
		rep(k,cyc.size()){
			int nk=k+1==cyc.size()?0:k+1;
			if(cnt[cyc[k]][cyc[nk]]>1)continue;
			disa[cyc[k]][cyc[nk]]=true;
			if(check(n)==-1){
				puts("YES");
				return 0;
			}
			disa[cyc[k]][cyc[nk]]=false;
		}
		puts("NO");
	}
	return 0;
}