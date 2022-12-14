#include <bits/stdc++.h>
#define N 20005
const double pi=acos(-1);
int read(){
	int t=0;
	char c=getchar();
	while (! ((c>47) && (c<58)))
		c=getchar();
	while ((c>47) && (c<58))
		t=t*10+c-48,c=getchar();
	return t;
}
double f[55][N],u[105][N];
int p[105][N],q[105][N],x[105],y[105],z[105];
bool b[55];
int i,j,k,m,n,t,v,w;
struct cpx{
	double r,i;
	inline cpx operator + (const cpx t) const{
		return (cpx) {r+t.r,i+t.i};
	}
	inline cpx operator - (const cpx t) const{
		return (cpx) {r-t.r,i-t.i};
	}
	inline cpx operator * (const cpx t) const{
		return (cpx) {r*t.r-i*t.i,r*t.i+i*t.r};
	}
};
cpx W[N*4][2],X[N*4],Y[N*4],Z[N*4];
double O[N*4],P[N*4],Q[N*4];
int rev[N*4];
inline void pre_FFT(int l){
	for(w=1;w<=l;w=w<<1);
	w=w<<1;
	for(int i=0;i<w;i++){
		W[i][0]=(cpx){cos(2*pi*i/w),sin(2*pi*i/w)};
		W[i][1]=(cpx){cos(2*pi*i/w),-sin(2*pi*i/w)};
	}
	for(int i=0;i<w;i++){
		rev[i]=0;
		for(int j=i,k=1;k<w;j=j>>1,k=k<<1) rev[i]=rev[i]<<1|(j&1);
	}
}
inline void FFT(cpx *T,int t){
	for(int i=0;i<w;i++) if(i<rev[i]) std::swap(T[i],T[rev[i]]);
	cpx x,y;
	for(int i=1;i<w;i=i<<1) for(int j=0;j<w;j=j+(i<<1)) for(int k=0;k<i;k++)
		x=T[j+k],y=W[w/(i<<1)*k][t]*T[i+j+k],T[j+k]=x+y,T[i+j+k]=x-y;
	if(t) for(int i=0;i<w;i++) T[i].r=T[i].r/w;
}
inline void turncpx(double *x,cpx *y){
	for(int i=0;i<w;i++) y[i].r=x[i],y[i].i=0;
	FFT(y,0);
}
inline void turnnum(cpx *x,double *y){
	FFT(x,1);
	for(int i=0;i<w;i++) y[i]=x[i].r;
}
inline void main_FFT(double *x,double *y,double *z){
	turncpx(x,X);
	turncpx(y,Y);
	for(int i=0;i<w;i++) Z[i]=X[i]*Y[i];
	turnnum(Z,z);
}
inline void pre(){
	n=read(),m=read(),k=read(),v=read();
	for (int i=1;i<=m;i++){
		x[i]=read(),y[i]=read(),z[i]=read();
		for(int j=1;j<=k;j++) p[i][j]=read();
		for(int j=k;j>=0;j--) q[i][j]=q[i][j+1]+p[i][j];
	}
	for (int i=1;i<=n;i++) f[i][k+1]=1e8;
	f[n][k+1]=v;
	for (int i=1;i<=n;i++){
		t=0;
		for(int j=1;j<=n;j++) if((!b[j])&&((!t)||(f[j][k+1]<f[t][k+1]))) t=j;
		b[t]=true;
		for(int j=1;j<=m;j++) if((!b[x[j]])&&(f[x[j]][k+1]>f[y[j]][k+1]+z[j]))
			f[x[j]][k+1]=f[y[j]][k+1]+z[j];
	}
}
inline void merge(int l,int r){
	if (l==r){
		for(int i=1;i<=n;i++) f[i][l]=1e8;
		f[n][l]=0;
		for(int i=1;i<=m;i++) u[i][l]=u[i][l]+z[i]+q[i][l+1]/1e5*f[y[i]][k+1];
		for(int i=1;i<=m;i++) f[x[i]][l]=std::min(f[x[i]][l],u[i][l]);
	}
	else{
		int mid=(l+r)/2;
		merge(l,mid);
		pre_FFT(r-l+1);
		for(int i=1;i<=m;i++){
			for(int j=l;j<=mid;j++) P[j-l]=f[y[i]][j];
			for(int j=l;j<=r;j++) Q[j-l]=p[i][j-l+1]/1e5;
			main_FFT(P,Q,O);
			for(int j=mid+1;j<=r;j++) u[i][j]=u[i][j]+O[j-l-1];
			for(int j=0;j<w;j++) O[j]=P[j]=Q[j]=0;
		}
		merge(mid+1,r);
	}
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	pre();
	merge(0,k);
	printf("%.10lf",f[1][k]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}