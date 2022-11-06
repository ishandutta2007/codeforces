#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 1000009
using namespace std;

int n,m,f[209],g[209],f0[209],g0[209];
char s[N],a[N],b[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
bool check(char x,char y){
	if (f[x] && f[x]!=y) return 0;
	if (g[y] && g[y]!=x) return 0;
	return 1;
}
void gao(){
	int i,j,now=0;
	for (i='a'; i<='a'+m-1; i++)
		for (j='a'; j<='a'+m-1; j++) if (check(i,j)){
			f[i]=j; g[j]=i; break;	
		}
	puts("YES");
	for (i='a'; i<='a'+m-1; i++) putchar(f[i]); puts("");
}
bool solve(){
	int i,j,k;
	for (i=1; i<=n; i++){
		if (a[i]==b[i]){
			if (!check(s[i],a[i])) return 0;
			f[s[i]]=a[i]; g[a[i]]=s[i];
		} else{
			for (j=a[i]+1; j<b[i]; j++){
				if (check(s[i],j)){
					f[s[i]]=j; g[j]=s[i];
					gao(); return 1;
				}
			}
			memcpy(f0,f,sizeof(f)); memcpy(g0,g,sizeof(g));
			if (check(s[i],a[i])){
				f[s[i]]=a[i]; g[a[i]]=s[i];
				for (j=i+1; j<=n; j++){
					for (k='a'+m-1; k>=a[j]; k--) if (check(s[j],k)){
						f[s[j]]=k; g[k]=s[j];
						if (k>a[j]){ gao(); return 1; }
						break;
					}
					if (k<a[j]) break;
				}
				if (j>n){ gao(); return 1; }
			}
			memcpy(f,f0,sizeof(f)); memcpy(g,g0,sizeof(g));
			if (check(s[i],b[i])){
				f[s[i]]=b[i]; g[b[i]]=s[i];
				for (j=i+1; j<=n; j++){
					for (k='a'; k<=b[j]; k++) if (check(s[j],k)){
						f[s[j]]=k; g[k]=s[j]; 
						if (k<b[j]){ gao(); return 1; }
						break;
					}	
					if (k>b[j]) break;
				}
				if (j>n){ gao(); return 1; }
			}
			return 0;
		}
	}
	gao(); return 1;
}
int main(){
	int cas=read();
	while (cas--){
		scanf("%d",&m);
		scanf("%s%s%s",s+1,a+1,b+1);
		n=strlen(s+1);
		memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
		if (!solve()) puts("NO");
	}
	return 0;
}