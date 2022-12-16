#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

const int N=200200;
struct Node;
typedef Node *np;
struct Node{
	np ch[2];
	int ans;
	Node():ch{NULL},ans(0){}
	void dfs(){
		D(i,2)if(ch[i])ch[i]->dfs();
		D(i,2)if(ch[i])ans=max(ans,ch[i]->ans);
		if(ch[0]&&ch[1])ans++;
	}
};
np rt=new Node();
void ins(np &r,int v,int dep=29){
	if(!r)r=new Node();
	if(dep==-1){
		r->ans=1;
		return;
	}
	ins(r->ch[(v>>dep)&1],v,dep-1);
}
int main(){
	int n=read();
	F(i,1,n)ins(rt,read());
	rt->dfs();
	printf("%d\n",n-rt->ans);
	return 0;
}