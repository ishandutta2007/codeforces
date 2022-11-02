#include<cstdio>
const int N=200005;
typedef long long ll; 
struct p{
	int l,r,u,d;
}a[N],b[N];
int T,n,i,x[N],y[N],X[N],Y[N],A,B;
ll ans;
char s[N];
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
ll Min(ll x,ll y){
	return x<y?x:y;
}
void Down(p &a){
	a.u--;a.d--;
}
void Up(p &a){
	a.u++;a.d++;
}
void Right(p &a){
	a.l++;a.r++;
}
void Left(p &a){
	a.l--;a.r--;
}
void Get(p a,p b){
	A=max(b.u,a.u)-min(b.d,a.d)+1;
	B=max(b.r,a.r)-min(b.l,a.l)+1;
	ans=Min(ans,1ll*A*B);
}
void work(){
	for(n=0;s[n+1];n++);
	for(i=1;i<=n;i++){
		x[i]=x[i-1];y[i]=y[i-1];
		a[i]=a[i-1];
		if(s[i]=='W'){y[i]++;a[i].u=max(a[i].u,y[i]);}
		if(s[i]=='S'){y[i]--;a[i].d=min(a[i].d,y[i]);}
		if(s[i]=='A'){x[i]--;a[i].l=min(a[i].l,x[i]);}
		if(s[i]=='D'){x[i]++;a[i].r=max(a[i].r,x[i]);}
	}
	X[n+1]=x[n];Y[n+1]=y[n];
	b[n+1]=(p){x[n],x[n],y[n],y[n]};
	for(i=n;i;i--){
		X[i]=X[i+1];Y[i]=Y[i+1];
		b[i]=b[i+1];
		if(s[i]=='S'){Y[i]++;b[i].u=max(b[i].u,Y[i]);}
		if(s[i]=='W'){Y[i]--;b[i].d=min(b[i].d,Y[i]);}
		if(s[i]=='D'){X[i]--;b[i].l=min(b[i].l,X[i]);}
		if(s[i]=='A'){X[i]++;b[i].r=max(b[i].r,X[i]);}
	}	
	ans=1ll*(a[n].r-a[n].l+1)*(a[n].u-a[n].d+1);
	for(i=1;i<n;i++){
		Up(b[i+1]);
		Get(a[i],b[i+1]);
		Down(b[i+1]);
		Left(b[i+1]);
		Get(a[i],b[i+1]);
		Right(b[i+1]);
		Down(b[i+1]);
		Get(a[i],b[i+1]);
		Up(b[i+1]);
		Right(b[i+1]);	
		Get(a[i],b[i+1]);	
		Left(b[i+1]);
	}
	printf("%I64d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		work();
	}
	return 0;
}