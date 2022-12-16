#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const double pi=acos(-1);
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define Rep(i,u) for(int i=head[u];i;i=Next[i])
#define clr(a) memset(a,0,sizeof a)
#define pb push_back
#define mp make_pair
#define putk() putchar(' ')
ld eps=1e-9;
ll pp=1000000007;
ll mo(ll a,ll pp){if(a>=0 && a<pp)return a;a%=pp;if(a<0)a+=pp;return a;}
ll powmod(ll a,ll b,ll pp){ll ans=1;for(;b;b>>=1,a=mo(a*a,pp))if(b&1)ans=mo(ans*a,pp);return ans;}
ll gcd(ll a,ll b){return (!b)?a:gcd(b,a%b);}
ll read(){
	ll ans=0;
	char last=' ',ch=getchar();
	while(ch<'0' || ch>'9')last=ch,ch=getchar();
	while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
	if(last=='-')ans=-ans;
	return ans;
}
void put(ll a){
	if(a<0)putchar('-'),a=-a;
	int top=0,q[20];
	while(a)q[++top]=a%10,a/=10;
	top=max(top,1);
	while(top--)putchar('0'+q[top+1]);
}
//head
char str[100][100];
int len[100];
int n,m;
int find(int t,int w){
	rep(i,0,m-1){
		int pf=1;
		rep(j,1,m)
			if(str[t][i+j]!=str[1][w+j]){
				pf=0;
				break;
			}
		if(pf)return i;
	}
	return 1000000;
}
int main(){
	n=read();
	rep(i,1,n){
		scanf("%s",str[i]+1);
		len[i]=strlen(str[i]+1);
		rep(j,1,len[i])str[i][len[i]+j]=str[i][j];
	}
	rep(i,2,n)
		if(len[i]!=len[1]){
			puts("-1");
			return 0;
		}
	m=len[1];
	int ans=1000000000;
	rep(i,0,m-1){
		int tot=i;
		rep(j,2,n)
			tot+=find(j,i);
		ans=min(ans,tot);
	}
	if(ans<10000)cout<<ans<<endl;
	else cout<<-1<<endl;
}