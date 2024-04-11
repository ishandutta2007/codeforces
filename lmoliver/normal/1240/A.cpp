#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=LL>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

const int N=2.1e5;
int p[N];

int main(){
	int q=read();
	D(_,q){
		int n=read();
		F(i,1,n){
			p[i]=read()/100;
		}
		sort(p+1,p+n+1,greater<int>());
		int x=read(),a=read();
		int y=read(),b=read();
		LL k=read();
		LL cur=0;
		map<int,priority_queue<int>> ws;
		F(i,1,n){
			int w=(i%a==0?x:0)+(i%b==0?y:0);
			ws[0].push(p[i]);
			ws.insert({w,priority_queue<int>()});
			auto it=ws.find(w);
			while(it!=ws.begin()){
				auto pv=prev(it);
				int v=pv->second.top();
				pv->second.pop();
				it->second.push(v);
				cur+=(LL)(it->first-pv->first)*v;
				it=pv;
			}
			if(cur>=k){
				printf("%d\n",i);
				goto ok;
			}
		}
		printf("%d\n",-1);
		ok:;
	}
	return 0;
}