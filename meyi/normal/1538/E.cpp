#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
inline int calc(string s){
	ri ret=0;
	for(ri i=0;i<s.size();++i)
		if(s.substr(i,4)=="haha")
			++ret;
	return ret;
}
struct node{
	string pre,suf;
	ll cnt;
	inline node(string s=""){
		cnt=calc(s);
		pre=s.substr(0,3);
		suf=s.substr(max(s.size(),3u)-3,3);
	}
};
inline node operator+(const node &x,const node &y){
	node ret;
	ret.cnt=x.cnt+y.cnt+calc(x.suf+y.pre);
	ret.pre=x.pre+y.pre;
	ret.pre=ret.pre.substr(0,3);
	ret.suf=x.suf+y.suf;
	ret.suf=ret.suf.substr(max(ret.suf.size(),3u)-3,3);
	return ret;
}
int n,t;
map<string,node>p;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		string op,x,y,z;
		p.clear();
		while(n--){
			cin>>x>>op;
			if(op==":="){
				cin>>y;
				p[x]=node(y);
			}
			else{
				cin>>y>>z>>z;
				p[x]=p[y]+p[z];
			}
		}
		printf("%lld\n",p[x].cnt);
	}
	return 0;
}