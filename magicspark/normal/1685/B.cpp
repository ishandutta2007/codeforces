/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int T,a,b,c,d;
string s;
int sum=0;
vector<int>ab,ba;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c>>d>>s;
		int s1=a+c+d,s2=b+c+d;
		for(char c:s)if(c=='A')s1--;else s2--;
		if(s1||s2){
			puts("NO");
			continue;
		}
		int prv=0;sum=0;
		ab.clear();ba.clear();
		for(int i=0;i<=s.size();i++){
			if(i&&(i==s.size()||s[i]==s[i-1])){
				int len=i-prv;
				if(len>1){
					if(len&1){
						sum+=len/2;
					}else{
						if(s[prv]=='A')ab.push_back(len/2);
						else ba.push_back(len/2);
					}
				}
				prv=i;
			}
		}
		sort(ab.begin(),ab.end());
		sort(ba.rbegin(),ba.rend());
		for(int i=0;i<ab.size();i++){
			if(c>=ab[i]){
				c-=ab[i];
				continue;
			}
			d-=max(0,ab[i]-1-c);c=0;
			for(int j=i+1;j<ab.size();j++)d-=ab[j]-1;
			break;
		}
		int tk=min(c,sum);
		c-=tk;sum-=tk;d-=sum;
		for(int i=0;i<ba.size();i++){
			if(c>0){
				int tk=min(ba[i]-1,c);
				c-=tk;d-=(ba[i]-1-tk);
			}else{
				d-=ba[i];
			}
		}
		puts(c<=0&&d<=0?"YES":"NO");
	}
	return 0;
}