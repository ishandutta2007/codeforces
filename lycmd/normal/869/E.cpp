#include<bits/stdc++.h>
using namespace std;
int const N=2505,MOD=998244353;
int n,m,q,v=1,t,tr[N][N];
map<array<int,4>,int>p;
void add(int&x,int y){
	if((x+=y)>=MOD)x-=MOD;
	if(x<0)x+=MOD;
}
void add(int x,int y,int v){
	for(int i=x;i<N;i+=i&-i)
		for(int j=y;j<N;j+=j&-j)
			add(tr[i][j],v);
}
int ask(int x,int y){
	int res=0;
	for(int i=x;i;i&=i-1)
		for(int j=y;j;j&=j-1)
			add(res,tr[i][j]);
	return res;
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m>>q;q--;){
		int op,ax,ay,bx,by;
		switch(cin>>op>>ax>>ay>>bx>>by,op){
			case 1:
				p[{ax,ay,bx,by}]=v=v*3ll%MOD,
				add(ax,ay,v),add(bx+1,by+1,v),
				add(ax,by+1,-v),add(bx+1,ay,-v);break;
			case 2:
				t=-p[{ax,ay,bx,by}],
				add(ax,ay,t),add(bx+1,by+1,t),
				add(ax,by+1,-t),add(bx+1,ay,-t);break;
			case 3:cout<<(ask(ax,ay)==ask(bx,by)?"Yes\n":"No\n");
		}
	}
}