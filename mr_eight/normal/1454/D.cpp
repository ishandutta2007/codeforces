//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
//#pra gma G CC opti mize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
template<class T>
inline T read(T &x) {
	x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
	if(fu)x=-x;
}
inline int read(){
	int x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
	return fu?-x:x;
}
vector<pair<ll,int> >v;
inline bool cmp(pair<ll,int>a,pair<ll,int>b){
	return a.second>b.second;
}
ll sum[10002];
inline void fen(ll x){v.clear();
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			v.push_back(make_pair(i,1));
			x/=i;
			while(x%i==0){
				v[v.size()-1].second++;
				x/=i;
			}
		}
	}if(x!=1)v.push_back(make_pair(x,1));
	sort(v.begin(),v.end(),cmp);
	F(i,0,v[0].second)sum[i]=1;
	F(i,0,v.size()-1){
		F(j,v[0].second-v[i].second+1,v[0].second){
			sum[j]*=v[i].first;
		}
	}cout<<v[0].second<<'\n';
	F(i,1,v[0].second){
		cout<<sum[i]<<' ';
	}cout<<'\n';
}
int main(){
    ll t,n;
    cin>>t;
    while(t--){
    	cin>>n;
    	fen(n);
	}
    return 0;
}