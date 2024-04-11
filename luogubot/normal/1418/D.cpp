#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e5+10;
#define fi first
#define se second
set<int> s;
multiset<int> ds;
void ins(int x){
	auto it=s.insert(x).fi;
	if(s.size()==1)return;
	if(it==s.begin()){
		ds.insert(*next(it)-*it);
	}else if(next(it)==s.end()){
		ds.insert(*it-*prev(it));
	}else{
		ds.erase(ds.find(*next(it)-*prev(it)));
		ds.insert(*next(it)-*it);
		ds.insert(*it-*prev(it));
	}
}
void del(int x){
	auto it=s.find(x);
	if(it!=s.begin()&&next(it)!=s.end()){
		ds.insert(*next(it)-*prev(it));
	}
	if(it!=s.begin()){
		ds.erase(ds.find(*it-*prev(it)));
	}if(next(it)!=s.end()){
		ds.erase(ds.find(*next(it)-*it));
	}s.erase(it);
}
void out(){
	if(!s.size())puts("0");
	else printf("%lld\n",*s.rbegin()-*s.begin()-*ds.rbegin());
}
int n,q;
signed main(){
	ds.insert(0);
	n=read(),q=read();
	For(i,1,n)ins(read());
	out();
	while(q--){
		int op=read(),x=read();
		if(op==0)del(x);else ins(x);
		out();
	}
	return 0;
}//fas