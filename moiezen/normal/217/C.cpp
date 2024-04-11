#include <cstdio>
#define rep(x) for(int x=0;x<=1;x++)
struct node{
	bool v[2][2];
};
bool jud(int a,int b,char c){
	if(c=='&') return a&b;
	else if(c=='|') return a|b;
	else return a^b;
}
node solve(){
	char ch=getchar();
	node res;
	if(ch=='('){
		node lef,rig;
		lef=solve();ch=getchar();rig=solve();
		rep(i) rep(j) res.v[i][j]=0;
		rep(i1) rep(j1) rep(i2) rep(j2) res.v[jud(i1,i2,ch)][jud(j1,j2,ch)]|=lef.v[i1][j1]&rig.v[i2][j2];
		ch=getchar();
	}
	else rep(i) rep(j) res.v[i][j]=ch=='?'?i^j:i==ch-'0'&&j==ch-'0';
	return res;
	
}
int main(){
	int n;scanf("%d\n",&n);
	printf(solve().v[0][1]?"YES":"NO");
}