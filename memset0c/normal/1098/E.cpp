#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr, "Running on Line %d in Function %s\n", __LINE__, __FUNCTION__)
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read() {
	char ch = getchar();
	int nega = 1;
	while (!isdigit(ch)) {
		if (ch == '-') nega = -1;
		ch = getchar();
	}
	int ans = 0;
	while (isdigit(ch)) {
		ans = ans * 10 + ch - 48;
		ch = getchar();
	}
	if (nega == -1) return -ans;
	return ans;
}
typedef pair<int, int> pii;
#define N 100005
int st[N][19], a[N], lg[N], n;
int query(int l, int r) {
	int t = lg[r - l + 1];
	return __gcd(st[l][t], st[r - (1 << t) + 1][t]);
}
inline int s(int n) { return n * (n + 1) / 2; }
int f(int n, int a, int b, int c) {
	if (!a) return (n + 1) * (b / c);
	if (a < 0 || b < 0 || a >= c || b >= c) {
		int A = a % c, B = b % c;
		(A < 0) && (A += c), (B < 0) && (B += c);
		return f(n, A, B, c) + ((a - A) / c) * s(n) + ((b - B) / c) * (n + 1);
	}
	int m = (a * n + b) / c;
	return n * m - f(m - 1, c, c - b - 1, a);
}
int chk(int val) {
	int ans = 0, r = 1, sum = a[1], cnt = a[1], las = 0;
	for (int i = 1; i <= 100000; i++) {
		if (!a[i]) continue;
		if (i > val) continue;
		sum -= i * a[i], cnt -= a[i];
		int tmp = 0;
		if (val / i <= a[i]) {
			ans += (val / i) * (a[i] - val / i + 1);
			tmp = a[i] - val / i + 1;
		}
		while (r <= 100000 && i * (a[i] - tmp) + sum <= val) {
			r++;
			cnt += a[r], sum += r * a[r];
		}
		// assert(tmp<=a[i]);
		if (r > 100000) {
			ans += (a[i] - tmp) * cnt + s(a[i] - tmp);
			continue;
		}
		// printf("%d %d\n",i,sum);
		while (tmp < a[i]) {
			if (sum >= val) {
				int R = val - (sum - r * a[r]) - i * (a[i] - tmp);
				ans += (a[i] - tmp) * (cnt - a[r]) + s(a[i] - tmp);
				// printf("%lld %lld %lld %lld\n",a[i]-tmp-1,i,R,r);
				ans += f(a[i] - tmp - 1, i, R, r);
				tmp = a[i];
			} else {
				int QAQ = (val - sum - 1) / i;
				assert(tmp + QAQ <= a[i]);
				int R = val - (sum - r * a[r] + QAQ * i) - i * (a[i] - tmp - QAQ);
				ans += (a[i] - tmp - QAQ) * (cnt - a[r] + QAQ) + s(a[i] - tmp - QAQ);
				ans += f(a[i] - tmp - QAQ - 1, i, R, r);
				tmp = a[i] - QAQ;
			}
			// cout<<ans<<endl;
			if (tmp == a[i]) break;
			while (r <= 100000 && i * (a[i] - tmp) + sum <= val) {
				r++;
				cnt += a[r], sum += r * a[r];
			}
			if (r > 100000) {
				ans += (a[i] - tmp) * cnt + s(a[i] - tmp);
				break;
			}
		}
		// printf("%lld %lld\n",i,ans-las);
		las = ans;
	}
	return ans;
}
signed main() {
	for (int i = 2; i < N; i++) lg[i] = lg[i / 2] + 1;
	cin >> n;
	for (int i = 1; i <= n; i++) st[i][0] = read();
	for (int i = 1; i <= 18; i++)
		for (int j = 1; j + (1 << i) - 1 <= n; j++) st[j][i] = __gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
	for (int i = 1; i <= n; i++) {
		int cur = n;
		while (cur >= i) {
			int val = query(i, cur), l = i, r = cur, res;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (query(i, mid) > val)
					l = mid + 1;
				else
					r = mid - 1, res = mid;
			}
			a[val] += cur - res + 1;
			// printf("%d %d %d\n",i,cur,val);
			cur = res - 1;
		}
	}
	// for(int i=1;i<=12;i++) printf("%d%c",a[i]," \n"[i==12]);
	int l = 1, r = INF, ans;
	int sum = n * (n + 1) / 2;
	sum = sum * (sum + 1) / 2;
	// cout<<sum<<endl;
	// cout<<chk(30)<<endl;
	// for(int i=1;i<=100;i++) printf("%lld\n",chk(i));
	// return 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (chk(mid) >= (sum + 1) / 2)
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	cout << ans << endl;
	fprintf(stderr, "clocks: %.4lf\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}


/*
#include<bits/stdc++.h>
using i64=long long;
const int S=1<<21; char ibuf[S],*iS,*iT,obuf[S],*oS=obuf,*oT=oS+S-1;
#define flush() (fwrite(obuf,1,oS-obuf,stdout),oS=obuf,void())
#define getchar() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,S,stdin),(iS==iT?EOF:*iS++)):*iS++)
#define putchar(x) (*oS++=(x),oS==oT?flush():void())
struct Flusher_{~Flusher_(){flush();}}flusher_;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline T gcd(T n,T m){return m?gcd(m,n%m):n;}
const int N=1e5+10,L=20;
int n,m,v[N],p[N][L],lg[N];
i64 a[N],s[N],f[N];
inline int ask(int l,int r){
	int k=lg[r-l+1];
	return gcd(p[l][k],p[r-(1<<k)+1][k]);
}
i64 simgcd(i64 n,i64 a,i64 b,i64 c){
	if(!a)return (n+1)*(b/c);
	if(a<0||b<0||a>=c||b>=c){
		i64 A=a%c; if(A<0)A+=c;
		i64 B=b%c; if(B<0)B+=c;
		return simgcd(n,A,B,c)+(a-A)/c*(n*(n+1)>>1)+(b-B)/c*(n+1);
	}
	i64 m=(a*n+b)/c;
	return n*m-simgcd(m-1,c,c-b-1,a);
}
i64 calc(i64 a,i64 n,i64 b,i64 m,i64 x){
	i64 r=std::min(n,x/a),l=std::min(r,std::max((x-b*m)/a,0ll))+1;
	return (l-1)*m+simgcd(r-l,a,x-a*r,b);
}
i64 count(i64 lim){
	i64 res=0;
	for(int i=1;i<=m;i++){
		i64 x=std::min(a[i],lim/i);
		res+=x*(x+1)/2+x*(a[i]-x);
	}
	for(int l=2,r=1;l<=m;++l,--r,r=std::max(r,l-1)){
		res+=a[l-1]*(s[r]-s[l-1]);
		while((r+1)<=m&&l+r+f[r]-f[l-1]<=lim){
			res+=calc(l-1,a[l-1],r+1,a[r+1],lim-f[r]+f[l-1]);
			r++;
		}
	}
	return res;
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),lg[0]=-1;
	for(int i=1;i<=n;i++)read(v[i]),p[i][0]=v[i];
	for(int i=1;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int j=1;j<20;j++)
		for(int i=1,t;i<=n;i++){
			p[i][j]=p[i][j-1],t=i+(1<<(j-1));
			if(t<=n)p[i][j]=gcd(p[i][j],p[t][j-1]);
		}
	for(int i=1;i<=n;i++){
		int u=v[i],j=i;
		while(true){
			int l=j,r=n;
			a[u]+=1-l;
			while(l<=r){
				int mid=(l+r)>>1;
				ask(i,mid)==u?(j=mid,l=mid+1):(r=mid-1);
			}
			a[u]+=j;
			if((++j)>n)break;
			u=ask(i,j);
		}
	}
	m=*std::max_element(v+1,v+n+1);
	// for(int i=1;i<=m;i++)printf("%lld%c",a[i]," \n"[i==m]);
	for(int i=1;i<=m;i++){
		s[i]=s[i-1]+a[i];
		f[i]=f[i-1]+a[i]*i;
	}
	i64 l=0,r=1e18,mid,res=-1,ele=n;
	for(int k=0;k<2;k++)ele=ele*(ele+1)/2;
	while(l<=r){
		mid=(l+r)>>1;
		count(mid)>=(ele+1)/2?(res=mid,r=mid-1):(l=mid+1);
		if(v[1]==87416){
			double x=clock()/(double)CLOCKS_PER_SEC;
			if(x>1.5)printf("%lld %lld | clocks: %.4lf\n",l,r,x);
			if(x>2.2)return 0;
		}
	}
	// for(int i=1;i<=m;i++)printf("count(%d)=%lld\n",i,count(i));
	printf("%lld\n",res);
	fprintf(stderr,"clocks: %.4lf\n",clock()/(double)CLOCKS_PER_SEC);
}
*/