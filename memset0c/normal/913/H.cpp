#include<bits/stdc++.h>
#define fi first
#define se second
const int N=100,mod=998244353;
int n,s[N];
double t;
struct z{
	int x;
	z(int x=0):x(x){}
	friend inline z operator*(z a,z b){return (long long)a.x*b.x%mod;}
	friend inline z operator-(z a,z b){return (a.x-=b.x)<0?a.x+mod:a.x;}
	friend inline z operator+(z a,z b){return (a.x+=b.x)>=mod?a.x-mod:a.x;}
}inv[N],C[N][N];
inline z fpow(z a,int b){z s=1;for(;b;b>>=1,a=a*a)if(b&1)s=s*a;return s;}
inline z trans(int x){return x*fpow(1000000,mod-2);}
struct poly:std::vector<z>{
	using std::vector<z>::vector;
	inline z take(z x){
		z s=0,p=1;
		for(int i=0;i<size();i++)s=s+p*at(i),p=p*x;		
		return s;
	}
	inline poly opposite(){
		poly res=*this;
		for(z &x:res)x.x=x.x?mod-x.x:0;
		return res;
	}
};
inline poly operator+(poly a,const poly &b){
	if(b.size()>a.size())a.resize(b.size());
	for(int i=0;i<b.size();i++)a[i]=a[i]+b[i]; return a;
}
inline poly operator-(poly a,const poly &b){
	if(b.size()>a.size())a.resize(b.size());
	for(int i=0;i<b.size();i++)a[i]=a[i]-b[i]; return a;
}
inline poly integral(poly a){
	a.push_back(0);
	for(int i=(int)a.size()-1;i>=1;i--)a[i]=a[i-1]*inv[i];					
	return a.front()=0,a;
}
struct function:std::vector<std::pair<int,poly>>{
	using std::vector<std::pair<int,poly>>::vector;
	inline void print(){
		for(int i=0;i<size();i++){
			printf("%.3lf : ",at(i).fi/1e6);
			for(z j:at(i).se)printf("%d ",j.x);
			if(i)printf("[%d %d]",at(i).se.take(trans(at(i).fi)).x,at(i-1).se.take(trans(at(i).fi)).x);
			putchar('\n');
		}
	}
	inline function opposite(){
		function res=*this;
		for(auto &it:res)it.se=it.se.opposite();
		return res;
	}
}f[N];
inline function merge(const function &a,const function &b){
	int i=0,j=0; poly fa,fb; function c;
	while(i<a.size()&&j<b.size())
		if(a[i].fi==b[j].fi){
			c.push_back({a[i].fi,a[i].se+b[j].se});
			fa=a[i++].se;
			fb=b[j++].se;
		}else if(a[i].fi<b[j].fi){
			c.push_back({a[i].fi,a[i].se+fb});
			fa=a[i++].se;
		}else{
			c.push_back({b[j].fi,fa+b[j].se});
			fb=b[j++].se;
		}
	while(i<a.size())c.push_back({a[i].fi,a[i].se+fb}),i++;
	while(j<b.size())c.push_back({b[j].fi,fa+b[j].se}),j++;
	return c;
}
inline function integral(function a){
	z s=0;
	for(int i=0;i+1<a.size();i++){
		a[i].se=integral(a[i].se);
		s=s-a[i].se.take(trans(a[i].fi));
		a[i].se[0]=a[i].se[0]+s;
		s=a[i].se.take(trans(a[i+1].fi));
	}
	a.back().se=integral(a.back().se);
	s=s-a.back().se.take(trans(a.back().fi));
	a.back().se[0]=a.back().se[0]+s;
	return a;
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	inv[0]=inv[1]=1;
	for(int i=2;i<N;i++)inv[i]=(mod-mod/i)*inv[mod%i];
	for(int i=0;i<N;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf",&t),s[i]=t*1000000+0.5;
	f[1]={{0,{0,1}},{std::min(1000000,s[1]),{trans(std::min(1000000,s[1]))}}};
	auto do1=[&](poly a){
		poly b(a.size());
		for(int i=0;i<a.size();i++)
			for(int j=0;j<=i;j++)
				if((i+j)&1)b[j]=b[j]-a[i]*C[i][j];
				else       b[j]=b[j]+a[i]*C[i][j];
		return b;
	};
	auto do2=[&](function a){
		for(auto &it:a)it.fi+=1000000,it.se=do1(it.se);
		return a;
	};
	// printf("f[1]\n"),f[1].print();
	for(int i=2;i<=n;i++){
		f[i]=merge(f[i-1],do2(f[i-1]).opposite());
		// printf("p[%d]\n",i),do2(f[i-1]).print();
		while(f[i].size()&&f[i].back().fi>=s[i])f[i].pop_back();
		if(!f[i].size())return printf("0\n"),0;
		// printf("q[%d]\n",i),f[i].print();
		f[i]=integral(f[i]);
		f[i].push_back({s[i],{f[i].back().se.take(trans(s[i]))}});
		// printf("f[%d]\n",i),f[i].print();
	}
	printf("%d\n",f[n].back().se.take(trans(s[n])).x);
}