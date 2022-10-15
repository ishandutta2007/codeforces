//QwQcOrZ yyds!!!
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


const int N = 300005*30;
int tr01[2][N],f[2][31],ans,ans1,n,a[N],cnt=1;
vector<int> pos[N];

void insert(int a,int b,int c,int d)
{
	if(d<0) return;
	if(!tr01[(b>>d)&1][a]) tr01[(b>>d)&1][a]=++cnt;
	pos[tr01[(b>>d)&1][a]].push_back(c);
	insert(tr01[(b>>d)&1][a],b,c,d-1);
}

void dfs(int k,int val)
{
	if (tr01[0][k]) dfs(tr01[0][k],val-1);
	if (tr01[1][k]) dfs(tr01[1][k],val-1);
	if (!tr01[0][k]&&!tr01[1][k]) return;
	int num=0,res=0;
	for(int i=0;i<pos[tr01[0][k]].size();i++)
	{
		while(num<pos[tr01[1][k]].size()&&pos[tr01[1][k]][num]<pos[tr01[0][k]][i]) ++num;
		res+=num;
	}
	f[0][val]+=res;
	f[1][val]+=1ll*pos[tr01[0][k]].size()*pos[tr01[1][k]].size()-res;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),insert(1,a[i],i,29);
	dfs(1,29);
	for(int i=29;i>=0;i--)
	{
		ans1+=min(f[0][i],f[1][i]);
		if(f[1][i]<f[0][i])
			ans|=(1<<i);
	}
	writesp(ans1);writeln(ans);
}