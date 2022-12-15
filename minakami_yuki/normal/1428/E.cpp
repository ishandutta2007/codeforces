#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+10;
const LL INF=1e18;
const LL P=1e9+7;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void add(LL &x,LL y){
	x+=y;if(x>=P)x-=P;
}
int n,K;
struct node{
	LL x,y;
	LL sx,sy;
	LL t;
	node(LL xx=0,LL yy=0,LL sxx=0,LL syy=0,LL tt=0){
		x=xx;y=yy;sx=sxx;sy=syy;t=tt;
	}
};
bool operator < (node x,node y){
	return x.t<y.t;
}
priority_queue<node> Q;
LL cal(node u){
	node z;
	LL v=u.sx+u.sy;
	LL s=u.x*u.sx+u.y*u.sy;
	++v;
	z.x=s/v;
	if(z.x==0) return 0;
	z.sy=s%v;
	if(z.sy>0){
		z.y=z.x+1;
	}
	else z.y=0;
	z.sx=(s-z.y*z.sy)/z.x;
	if(z.x<z.y){
		swap(z.x,z.y);
		swap(z.sx,z.sy); 
	}
	return u.sx*u.x*u.x+u.sy*u.y*u.y-z.sx*z.x*z.x-z.sy*z.y*z.y;
}
int main(){
	LL v,s;
	node hhh;
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;++i){
		scanf("%I64d",&v);
		hhh=node(v,0,1,0);
		hhh.t=cal(hhh);
		Q.push(hhh);
	}
	//cout<<"y"<<endl;
	K=K-n;
	node u,z;
	while(K--){
		u=Q.top();Q.pop();
		v=u.sx+u.sy;
		s=u.x*u.sx+u.y*u.sy;
		++v;
		z.x=s/v;
		z.sy=s%v;
		if(z.sy>0){
			z.y=z.x+1;
		}
		else z.y=0;
		z.sx=(s-z.y*z.sy)/z.x;
		if(z.x<z.y){
			swap(z.x,z.y);
			swap(z.sx,z.sy); 
		}
		z.t=cal(z);
		Q.push(z);
	}
	LL ans=0;
	while(!Q.empty()){
		u=Q.top();Q.pop();
//		cout<<u.x<<" "<<u.sx<<endl;
//		cout<<u.y<<" "<<u.sy<<endl;
		ans+=u.x*u.x*u.sx;
		ans+=u.y*u.y*u.sy;
	}
	cout<<ans<<endl;
    return 0;
}