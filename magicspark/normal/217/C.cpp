/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
string n,s;
int A[22][22],O[22][22],X[22][22];
int l[1000005],r[1000005];
int func(int pos){
	if(s[pos]!='('){
		return s[pos]=='0'?1:(s[pos]=='1'?8:6);
	}
	int L=pos+1,R=(s[L]=='('?r[L]+1:L+1)+1;
	int x=func(L),y=func(R);
	if(s[R-1]=='&')return A[x][y];
	if(s[R-1]=='|')return O[x][y];
	if(s[R-1]=='^')return X[x][y];
	while(1);
}
int asswecan(){
	stack<int>stk;
	for(int i=0;i<s.size();i++){
		if(s[i]=='('){
			stk.push(i);
		}
		if(s[i]==')'){
			r[stk.top()]=i;
			l[i]=stk.top();
			stk.pop();
		}
	}
	return func(0);
}
int main(){
	cin>>n>>s;
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			for(int x1=0;x1<2;x1++){
				for(int x2=0;x2<2;x2++){
					for(int y1=0;y1<2;y1++){
						for(int y2=0;y2<2;y2++){
							if(!(i&(1<<x1+x1+x2)))continue;
							if(!(j&(1<<y1+y1+y2)))continue;
							int mul=(x1+x1+x2)&(y1+y1+y2);
							A[i][j]|=(1<<mul);
							mul=(x1+x1+x2)|(y1+y1+y2);
							O[i][j]|=(1<<mul);
							mul=(x1+x1+x2)^(y1+y1+y2);
							X[i][j]|=(1<<mul);
						}
					}
				}
			}
		}
	}
	int ans=asswecan();
	if(ans&6){
		puts("YES");
	}else{
		puts("NO");
	}
	cerr<<"sjctxdy"<<endl;
	cerr<<"orz sjc"<<endl;
	return 0;
}