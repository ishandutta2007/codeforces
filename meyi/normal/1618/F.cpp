#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
inline string to_str(ll k){
	string ret;
	while(k)ret+=48|(k&1),k>>=1;
	reverse(ret.begin(),ret.end());
	return ret;
}
inline void check(string x,string y){
	for(ri i=0;i<31;++i)
		for(ri j=0;j<31;++j)
			if(string(i,'1')+x+string(j,'1')==y)
				puts("YES"),exit(0);
	reverse(x.begin(),x.end());
	for(ri i=0;i<31;++i)
		for(ri j=0;j<31;++j)
			if(string(i,'1')+x+string(j,'1')==y)
				puts("YES"),exit(0);
}
string a,b;
ll x,y;
int main(){
	scanf("%lld%lld",&x,&y);
	if(x==y)return puts("YES"),0;
	a=to_str(x),b=to_str(y);
	if(a.back()=='0'){
		string tmp=a+'1';
		check(tmp,b);
		while(a.back()=='0')a.pop_back();
	}
	check(a,b);
	puts("NO");
	return 0;
}