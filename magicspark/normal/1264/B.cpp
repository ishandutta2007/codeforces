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
int a,b,c,d;
vector<int>ans;
void print(int x){
	if(x==1){
		ans.push_back(1);b-=1;
	}else{
		ans.push_back(2);c-=1;
	}
}
int main(){
	cin>>a>>b>>c>>d;
	int x=b-a,y=c-d;
	if(x==0&&y==0){
		puts("YES");
		for(int i=0;i<a;i++)cout<<"0 1 ";
		for(int i=0;i<c;i++)cout<<"2 3 ";
		return 0;
	}
	if(x<0||y<0){
		if(a==0&&b==0&&(d==c+1)){
			puts("YES");
			for(int i=0;i<c;i++)cout<<"3 2 ";cout<<3<<endl;
		}else if(c==0&&d==0&&(a==b+1)){
			puts("YES");
			for(int i=0;i<b;i++)cout<<"0 1 ";cout<<0<<endl; 
		}else puts("NO");
		return 0;
	}
	if(abs(x-y)>1){
		puts("NO");
	}else{
		int st;
		if(x>y){
			st=1;
		}else{
			st=2;
		}
		if(x==0||y==0)st=3-st;
		else print(st);
		for(int i=0;i<min(x,y)-1;i++){
			print(3-st);
			print(st);
		}
		if(a<0||b<0||c<0||d<0){
			puts("NO");
			return 0;
		}else{
			puts("YES");
			if(st==1){
				if(c){
					for(int i=0;i<d;i++)ans.push_back(2),ans.push_back(3);if(c>d)ans.push_back(2);
				}
				if(b){
					for(int i=0;i<a;i++)ans.push_back(1),ans.push_back(0);if(b>a)ans.push_back(1);
				}
			}else{
				if(b){
					for(int i=0;i<a;i++)ans.push_back(1),ans.push_back(0);if(b>a)ans.push_back(1);
				}
				if(c){
					for(int i=0;i<d;i++)ans.push_back(2),ans.push_back(3);if(c>d)ans.push_back(2);
				}
			}
		}
		for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";cout<<endl;
	}
	return 0;
}