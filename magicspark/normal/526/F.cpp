/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,pos[300005];
vector<pair<int,int> >opr,opr2;//pos,val
int f[1000005],f2[1000005];
void add(int x,int v){
	opr.push_back(make_pair(x,-v));
	x+=300002;f[x]+=v;
}
void add2(int x,int v){
	opr2.push_back(make_pair(x,-v));
	x+=300002;f2[x]+=v;
}
int calc_max(const vector<pair<int,int> >&L,const vector<pair<int,int> >&R){
	int nl=L.size(),nr=R.size();nl--;nr--;
	opr.clear();opr2.clear();
	int r=1;
	multiset<pair<int,int> >S;S.clear();
	int ret=0;
	for(int i=1;i<=nl;i++){
		while(r<=nr&&R[r].first<L[i].first){
			add(R[r].second+r-1,1);//equal to max-i
			S.insert(make_pair(-R[r].second,R[r].second+r-1));
			r++;
		}
		while(!S.empty()&&-S.begin()->first>L[i].second){
			int t=S.begin()->second;
			add(t,-1);
			add2(t+S.begin()->first,1);
			S.erase(S.begin());
		}
		ret+=f[L[i].first-i+300002]+f2[L[i].first-L[i].second-i+300002];
	}
	for(int i=0;i<opr.size();i++){
		f[opr[i].first+300002]+=opr[i].second;
	}
	for(int i=0;i<opr2.size();i++){
		f2[opr2[i].first+300002]+=opr2[i].second;
	}/*
	if(ret){
		cerr<<"------------"<<endl;
		cerr<<"Left:"<<endl;
		for(int i=1;i<=nl;i++){
			cerr<<L[i].first<<" "<<L[i].second<<endl;
		}
		cerr<<"Right"<<endl;
		for(int i=1;i<=nr;i++){
			cerr<<R[i].first<<" "<<R[i].second<<endl;
		}
		cerr<<"---------------"<<endl;
	}*/
	return ret;
}
int solve(int l,int r){
	if(l==r)return 1;
	int ret=solve(l,(l+r)/2)+solve((l+r)/2+1,r);
	vector<pair<int,int> >Left(1,make_pair(-inf,inf)),Right(1,make_pair(-inf,inf));//<Max,Min>
	int Max=-inf,Min=inf;
	for(int i=(l+r)/2;i>=l;i--){
		Max=max(Max,pos[i]);
		Min=min(Min,pos[i]);
		Left.push_back(make_pair(Max,Min));
	}
	Max=-inf;Min=inf;
	for(int i=(l+r)/2+1;i<=r;i++){
		Max=max(Max,pos[i]);
		Min=min(Min,pos[i]);
		Right.push_back(make_pair(Max,Min));
	}
	int add=calc_max(Left,Right)+calc_max(Right,Left);
	return ret+add;
}
signed main(){
	#ifdef LOCAL
		freopen("input.cpp","r",stdin);
	#endif
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++){
		int r,c;scanf("%I64d%I64d",&r,&c);
		pos[r]=c;
	}
	cout<<solve(1,n)<<endl;
	return 0;
}