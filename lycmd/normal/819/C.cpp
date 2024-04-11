#include<bits/stdc++.h>
#define gc() getchar()
#define pc(c) putchar(c)
#define node pair<int,int>
#define int long long
using namespace std;
int const N=1000010;
int t,n,m,s,n1,n2,n3,m1,m2,m3,s1,s2,s3,ans,flg[N];
int const pr[]={2,3,5,7,13,17,19,23,101};
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
auto gen=[](int l,int r){return rnd()%(r-l+1)+l;};
int read(){
	int x=0;char c=gc();
	while(c<48||c>57)c=gc();
	while(c>47&&c<58)x=(x<<1)+(x<<3)+(c^48),c=gc();
	return x;
}
void write(int x){
	if(x>9)write(x/10);
	pc((x%10)|48);
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int mul(int x,int y,int p){
	return (__int128)x*y%p;
}
int qpow(int x,int y,int p){
	return y?mul(qpow(mul(x,x,p),y>>1,p),y&1?x:1,p):1;
}
int test(int x,int y){
	int cnt=0,t=x-1;
	while(~t&1)t>>=1,cnt++;
	int k=qpow(y,t,x);
	if(k==1)return 1;
	for(int i=0;i<cnt;i++){
		if(k==x-1)return 1;
		k=mul(k,k,x);
	}
	return 0;
}
int checkprime(int x){
	if(x<2)return 0;
	for(int i=0;i<9;i++){
		if(x==pr[i])
			return 1;
		if(x%pr[i]==0)
			return 0;
		if(!test(x,pr[i]))
			return 0;
	}
	return 1;
}
int f(int x,int c,int p){
	return (mul(x,x,p)+c)%p;
}
int solve(int x){
	int s=0,t=0,c=gen(1,x),cur=1,g;
	for(int l=1;;l<<=1,s=t,cur=1){
		for(int stp=1;stp<=l;stp++){
			t=f(t,c,x),cur=mul(cur,abs(t-s),x);
			if(stp%127==0&&(g=gcd(cur,x))>1)
				return g;
		}
		if((g=gcd(cur,x))>1)
			return g;
	}
}
void largestpfac(int x,int&ans){
	if(x<2||x<=ans)
		return;
	if(checkprime(x)){
		ans=max(ans,x);return;
	}
	int t=x;
	while(t>=x)t=solve(x);
	while(x%t==0)x/=t;
	largestpfac(x,ans);
	largestpfac(t,ans);
}
vector<node>split(int n){
	vector<node>ans;
	ans.clear();
	while(n>1){
		int t=0,p=0;
		largestpfac(n,p);
		while(n%p==0)t++,n/=p;
		ans.push_back({p,t});
	}
	return ans;
}
vector<node>a;
vector<int>p;
void dfs(int x,int k){
	if(x==a.size()){
		ans+=(k<=n)+(k<s/k&&s/k<=n);
		return;
	}
	for(int i=0;i<=a[x].second;i++){
		dfs(x+1,k),k*=a[x].first;
		if(1.0*k*k>s)break;
	}
}
signed main(){
//	freopen("friends.in","r",stdin);
//	freopen("friends.out","w",stdout);
	for(int i=0;i<N;i++)
		flg[i]=i?-flg[i&i-1]:1;
	for(t=read();t--;){
		n1=read(),n2=read(),n3=read();
		m1=read(),m2=read(),m3=read();
		s1=read(),s2=read(),s3=read();
		n=n1*n2*n3,m=m1*m2*m3,s=s1*s2*s3*2;
		a=split(n),p.clear();
		for(auto i:a){
			int t=1;
			for(int j=0;j<i.second;j++)
				if(s%(t*=i.first)){
					p.push_back(t);break;
				}
		}
		ans=0;
		for(int i=0;i<1<<p.size();i++){
			int t=1;
			for(int j=0;j<p.size();j++)
				if((i>>j)&1)t*=p[j];
			ans+=flg[i]*m/t;
		}
		a=split(s),dfs(0,1);
		write(ans),pc(10);
	}
}//