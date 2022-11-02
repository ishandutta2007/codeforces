#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=411;
char a[N][N];
int f[N];
int fa(int i){return f[i]==i?i:f[i]=fa(f[i]);}
int d[N];
bool judge(int x,int y){
	if(d[x]!=d[y])return 0;
	rep(i,0,d[x]-1)
		if(a[x][i]!=a[y][i])return 0;
	return 1;
}
void calc(char *s,int tt){
	int len=strlen(s);
	for(int i=0;i<len;i++){
//		if(tt==10)debug(i),debug(len);
		if(s[i]=='h'){
			while(i&&s[i-1]=='k'){
				for(int j=i-1;j<len-1;j++)
					s[j]=s[j+1];
				i--,len--;
			}
		}
		if(s[i]=='u'){
			s[i]='o';
			len++;
			for(int j=len-1;j>=i+2;j--){
				s[j]=s[j-1];
			}
			s[i+1]='o';
		}
	}
	d[tt]=len;
}
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	int n;
	cin>>n;
	rep(i,1,n)f[i]=i;
	rep(i,1,n){
		cin>>a[i];
		calc(a[i],i);
	}
	rep(i,1,n)rep(j,1,i-1)if(judge(i,j))f[fa(j)]=fa(i);
//	cout<<"ok"<<endl;
	int ans=0;
	rep(i,1,n)if(fa(i)==i)ans++;
	cout<<ans<<endl;
}