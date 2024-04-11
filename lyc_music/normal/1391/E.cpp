//QwQcOrZ yyds!!!
//code**rcesnmsl
//code**rcesnmsl
//code**rcesnmsl
//code**rcesnmsl
//code**rcesnmsl
//code**rcesnmsl

//code**rcesnmsl
//code**rcesnmsl
//code**rcesnmsl

#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
#define pb push_back
#define N 500000
int n,m;
vector<int> ohh[N+1];
bool bl[N+1];
int fa[N+1],dep[N+1];
void dfs(int x)
{
	bl[x]=true;
	for(int i=0;i<ohh[x].size();i++){
		int y=ohh[x][i];
		if(bl[y])continue;
		fa[y]=x;dep[y]=dep[x]+1;
		dfs(y);
	}
}
vector<int> bdc[N+1];
int x,y,cnt,T;
void work()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)ohh[i].clear(),bdc[i].clear(),bl[i]=fa[i]=dep[i]=0;
	dep[1]=1;
	while(m--){
		x=read(),y=read();
		ohh[x].pb(y);ohh[y].pb(x);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		if(dep[i]>=n+1>>1){
			puts("PATH");
			writeln(dep[i]);
			while(i) writesp(i),i=fa[i];
			puts("");
			return;
		}
		else bdc[dep[i]].pb(i);
	puts("PAIRING");cnt=0;
	for(int i=1;i<=n;i++) cnt+=bdc[i].size()>>1;
	writeln(cnt);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<bdc[i].size();j+=2) writesp(bdc[i][j-1]),writeln(bdc[i][j]);
	}
}
signed main()
{
	T=read();
	while(T--) work();
}