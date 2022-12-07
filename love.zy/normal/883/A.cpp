#include<bits/stdc++.h> 
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,0x3f,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define MEMx(a,b) memset(a,b,sizeof(a));
#define INF (0x3f3f3f3f)
#define F (1000000007)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case #%d: %lld\n",kcase,ans);
#define PRi(a,n) For(i,n-1) cout<<a[i]<<' '; cout<<a[n]<<endl;
#define PRi2D(a,n,m) For(i,n) { \
						For(j,m-1) cout<<a[i][j]<<' ';\
						cout<<a[i][m]<<endl; \
						} 
#pragma comment(linker, "/STACK:102400000,102400000")
#define ALL(x) (x).begin(),(x).end()
#define gmax(a,b) a=max(a,b);
#define gmin(a,b) a=min(a,b);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return ((a-b)%F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
#define MAXN (212345)
ll n,m;
ll a,d,t[MAXN];
int main()
{
//	freopen("A.in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>m>>a>>d;
	For(i,m) cin>>t[i];
	t[++m]=1LL<<62LL;
  	
	ll waitA_t=d-d%a+a,ans=0;
	ll ca=waitA_t/a;
	ll nowt=0; // 
	For(i,m) {

		if (t[i]<=nowt) continue;
		if (nowt>=n*a) {
			nowt=t[i]+d;
			ans++;
			continue;
		}
		ll last_A=nowt/a*a+a;
		if (t[i]<last_A) {
			nowt=t[i]+d;
			ans++;
			continue;
		}
		nowt=last_A+d;
		ans++;
		last_A=nowt/a*a+a;
		while(t[i]-d-last_A>0 && n*a-last_A>0) {
			ll k = (t[i]-d-last_A)/waitA_t;
			gmin(k,( n*a-last_A)/waitA_t );
			if(k>5){
				k-=5;
				ans+=k;
				last_A+=k*waitA_t;
				nowt=last_A-waitA_t+d;
				
			}else break;
		}	
		i--;
		continue;
	}
	ans--;
	cout<<ans<<endl;

	return 0;
}