#include<bits/stdc++.h>
#define LL long long
#define F(p) for(int (p)=0;p<n;p++)
#define Fm(p) for(int (p)=0;p<m;p++)
#define Fd(p) for(int (p)=n-1;p>=0;p--)
#define Fdm(p) for(int (p)=m-1;p>=0;p--)
#define FI(p) for(int (p)=1;p<=n;p++)
#define FIm(p) for(int (p)=1;p<=m;p++)
#define FId(p) for(int (p)=n;p>=1;p--)
#define FIdm(p) for(int (p)=m;p>=1;p--)
#define FQ(q,l,r,up) for(int q=(l);(LL)q*(up)<=(LL)(r)*(up);q+=(up))
#define FP(t,p,l,r) for(t *p=(l);p<=(r);p++)
#define FdP(t,p,l,r) for(t *p=(l);p>=(r);p--)
const int INF=(1<<30)-(1<<6);
const LL LINF=((LL)1<<62)-(1<<6);
using namespace std;
template<int L,int R,class T=int>struct Parray{T arr[R-L+1];inline int& operator[] (int i){return arr[i-L];}};
void inline _read(int &x){scanf("%d",&x);}
void inline _read(char *x){scanf("%s",x);}
void inline _read(string &x){cin>>x;}
void inline readln(string &x){getline(cin,x);}
void inline _read(const char *x){scanf(x);}
template<typename T1>inline void read(T1 &x1){_read(x1);}
template<typename T1,typename T2>inline void read(T1 &x1,T2 &x2){_read(x1);read(x2);}
template<typename T1,typename T2,typename T3>inline void read(T1 &x1,T2 &x2,T3 &x3){_read(x1);read(x2,x3);}
template<typename T1,typename T2,typename T3,typename T4>inline void read(T1 &x1,T2 &x2,T3 &x3,T4 &x4){_read(x1);read(x2,x3,x4);}
int n,m,q;
int x[200200]={0},y[200200]={0};
int fa[200200]={0};
int nc[200200]={0};
int find(int x){
	return fa[x]=x==fa[x]?x:find(fa[x]);
}
bool u(int a,int b){
	int x=find(a);
	int y=find(b);
	if(x==y)return false;
	fa[x]=y;
	return true;
}
int main(){
	read(n,m,q);
	for(int i=1;i<=m;i++)fa[i]=i;
	for(int i=0;i<q;i++){
		int r,c;
		read(r,c);
		if(nc[r])u(nc[r],c);
		nc[r]=c;
		x[r]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(x[i]==0)ans++;
	int ni=1;
	for(int i=2;i<=m;i++)if(u(ni,i))ans++;
	cout<<ans;
	return 0;
}