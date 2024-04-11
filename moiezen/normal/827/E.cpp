#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define Rep(i,a,b) for (int i=(a);i<(b);i++)
#define Per(i,a,b) for (int i=(a);i>(b);i--)
#define deb printf("begin\n");
#define dee printf("end\n");
#define def printf("find\n");
#define p(x) printf("%d\n",x);
void read(int&x){
	x=0;int f=1;char ch=getchar();
	while ((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if (ch=='-'){f=-1,ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
#define G 3
#define maxn 500005
#define all 1048576
#define mod 998244353
int power(int a,int b,int p){
	int s=1,w=a;
	while (b){
		if (b&1)s=(ll)s*w%p;
		w=(ll)w*w%p;b>>=1;
	}
	return s;
}
int T,n;char s[maxn];int num[maxn];
int a[all],b[all],r[all];
void NTT(int*a,int n,int type){
	Rep(i,0,n)if (i<r[i])swap(a[i],a[r[i]]);
	for (int i=1;i<n;i<<=1){
		int wn=(type==1)?power(G,(mod-1)/i/2,mod):power(power(G,(mod-1)/i/2,mod),mod-2,mod);
		for (int j=0,del=i<<1;j<n;j+=del){
			int w=1;
			Rep(k,0,i){
				int x=a[j+k],y=(ll)w*a[j+k+i]%mod;
				a[j+k]=(x+y)%mod,a[j+k+i]=(x-y+mod)%mod;
				w=(ll)w*wn%mod;
			}
		}
	}
	if (type==-1)Rep(i,0,n)a[i]=(ll)a[i]*power(n,mod-2,mod)%mod;
}
bool ans[maxn];int res[maxn];
void doit(){
	int la=n-1,lb=n-1,l=0;
	//Rep(i,0,n)a[i]=num[i+1];
	//Rep(i,0,n)b[i]=num[n-i];
	rep(i,1,n)if (s[i]=='V')a[i-1]=1;
	rep(i,1,n)if (s[i]=='K')b[n-i]=1;
	for (la+=lb,lb=1;lb<=la;lb<<=1)l++;
	Rep(i,0,lb)r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	NTT(a,lb,1);NTT(b,lb,1);
	Rep(i,0,lb)a[i]=(ll)a[i]*b[i]%mod;
	NTT(a,lb,-1);
	//Rep(i,0,lb)printf("%d ",a[i]);printf("\n");
	rep(i,1,n)if (a[i-1])ans[n-i]=true;;
	std::reverse(a,a+2*n-1);
	rep(i,1,n)if (a[i-1])ans[n-i]=true;;
	Rep(i,0,lb)a[i]=b[i]=0;
}
void work(){
	read(n);rep(i,1,n)s[i]=getchar();rep(i,1,n)ans[i]=false;res[0]=0;
	//rep(i,1,n)printf("%c",s[i]);printf("\n");
	//rep(i,1,n)if (s[i]!='K')num[i]=1;else num[i]=0;rep(i,1,n)printf("%d ",num[i]);printf("\n");doit();
	//rep(i,1,n)if (s[i]!='V')num[i]=1;else num[i]=0;rep(i,1,n)printf("%d ",num[i]);printf("\n");doit();
	doit();
	rep(i,1,n)for (int j=i;j<=n;j+=i)if (ans[j]){ans[i]=true;break;}
	rep(i,1,n)if (!ans[i])res[++res[0]]=i;
	printf("%d\n",res[0]);rep(i,1,res[0])printf("%d ",res[i]);printf("\n");
}
int main(){
	read(T);while (T--)work();return 0;
}