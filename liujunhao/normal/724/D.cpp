#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
#define MAXN 100000
template<class T>
void Read(T &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
int n,m,fa[MAXN+10],size[MAXN+10],cnt;
char s[MAXN+10],ans[MAXN+10];
vector<int>pos[26];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void read(){
	Read(m);
	scanf("%s",s+1);
	n=strlen(s+1);
	int i;
	for(i=1;i<=n;i++){
		pos[s[i]-'a'].push_back(i);
		fa[i]=i,size[i]=1;
	}
}
bool vis[MAXN+10];
void solve(){
	int i;
	bool flag=0;
	for(i=25;i>=0;i--){
		flag=0;
		for(vector<int>::iterator j=pos[i].begin();j<pos[i].end();j++){
			int tsize=0;
			if(*j>1&&vis[*j-1])
				tsize+=size[find(*j-1)];
			if(*j<n&&vis[*j+1])
				tsize+=size[find(*j+1)];
			tsize++;
			if(tsize>=m){
				flag=1;
				continue;
			}
			if(*j>1&&vis[*j-1]){
				size[find(*j-1)]+=size[find(*j)];
				fa[fa[*j]]=fa[*j-1];
			}
			if(*j<n&&vis[*j+1]){
				size[find(*j+1)]+=size[find(*j)];
				fa[fa[*j]]=fa[*j+1];
			}
			vis[*j]=1;
		}
		if(flag)
			break;
	}
}
void print(){
	int i;
	for(i=1;i<=n;i++)
		if(!vis[i])
			ans[++cnt]=s[i];
	sort(ans+1,ans+cnt+1);
	puts(ans+1);
}
int main()
{
	read();
	solve();
	print();
}