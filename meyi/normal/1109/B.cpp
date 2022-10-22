#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
string s;
signed main(){
	cin>>s;
	if(all_of(s.begin(),s.begin()+(s.size()>>1),[&](char ch){return ch==s[0];}))return puts("Impossible"),0;
	auto check=[&](const string &t){
		if(s==t)return false;
		string tt=t;
		reverse(tt.begin(),tt.end());
		return t==tt;
	};
	for(ri i=0;i+1<s.size();++i)
		if(check(s.substr(i+1)+s.substr(0,i+1)))
			return putchar(49),0;
	putchar(50);
	return 0;
}