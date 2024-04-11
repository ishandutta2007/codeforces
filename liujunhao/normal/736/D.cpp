#include<cstdio>
#include<algorithm>
#include<bitset>
#define MAXM 500000
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-')
			f=1;
		else if(c=='?'){
			x=-1;
			return;
		}
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
}
bitset<2001>a[2001],inv[2001];
int n,m;
bool flag;
typedef pair<int,int>pii;
pii b[MAXM+10];
void read(){
	int u,v,i;
	Read(n),Read(m);
	for(i=1;i<=m;i++){
		Read(u),Read(v);
		a[u][v]=1;
		b[i]=pii(v,u);
	}
	for(i=1;i<=n;i++)
		inv[i][i]=1;
}
void gaussian_jordan(){
	int i,row,col;
	for(row=col=1;row<=n;row++,col++){
		for(i=row;i<=n&&!a[i][col];i++);
		if(i>n){
			flag=1;
			break;
		}
		if(i!=row)
			swap(a[i],a[row]),swap(inv[i],inv[row]);
		for(i=1;i<=n;i++)
			if(i!=row&&a[i][col])
				a[i]^=a[row],inv[i]^=inv[row];
	}
}
void solve(){
	gaussian_jordan();
	int i;
	for(i=1;i<=m;i++)
		if(flag||inv[b[i].first][b[i].second])
			puts("NO");
		else
			puts("YES");
}
int main()
{
	read();
	solve();
}