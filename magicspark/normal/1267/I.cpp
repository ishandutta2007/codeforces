/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int T,n;
vector<int>A,B;
bool smaller(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl;
	fflush(stdout);
	char c;cin>>c;
	if(c=='<')return true;
	else return false;
}
int match(int x){
	if(x%2)return x+1;
	else return x-1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		A.clear();B.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x=i*2-1,y=i*2;
			if(smaller(x,y))swap(x,y);
			//f[x]>f[y]
			A.push_back(x);B.push_back(y);
		}
		for(int i=0;i<B.size();i++){
			for(int j=i+1;j<B.size();j++){
				if(smaller(B[i],B[j]))swap(B[i],B[j]);
			}
		}
		int pos=0;for(int i=0;i<A.size();i++)if(A[i]==match(B[0]))pos=i;
		A.erase(A.begin()+pos);A.insert(A.begin(),match(B[0]));
		for(int i=1;i<A.size();i++){
			for(int j=i+1;j<A.size();j++){
				if(smaller(A[i],A[j]))swap(A[i],A[j]);
			}
		}
		for(int i=0;i<n;i++)cerr<<A[i]<<" ";cerr<<endl;
		for(int i=0;i<n;i++)cerr<<B[i]<<" ";cerr<<endl;
		for(int i=1;i<n;i++){
			smaller(A[i],B[n-i-1]);
		}
		cout<<"!"<<endl;
		fflush(stdout);
	}
	return 0;
}