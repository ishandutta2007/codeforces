#include<cstdio>
#include<cstring>
using namespace std;
const int N=800002,M=998244353,M0=3,M1=332748118;
int n,m,k,S[N],A[N],B[N],C[N],i;
int d[N],Len,l,Rs[N],Ans;
char s[N],t[N],c;
int ksm(int x,int p){
	int s=1;
	while(p){
		if(p&1)s=1ll*s*x%M;
		p>>=1;
		x=1ll*x*x%M;
	}
	return s;
}
void Re(char *s,int n){
	for(int i=0;i<n/2;i++){
		c=s[i];
		s[i]=s[n-i-1];
		s[n-i-1]=c;
	}
}
void init(){
	scanf("%d%d%d%s%s",&n,&m,&k,s,t);
	Re(t,m);
}
int max(int x,int y){
	return x>y?x:y;
}
void swap(int &x,int &y){
	int t=x;x=y;y=t;
}
void NTT(int *A,int t){
	int i,j,k,x,y,w,w0;
	for(i=0;i<Len;i++)
		if(Rs[i]>i)
			swap(A[i],A[Rs[i]]);
	for(i=1;i<Len;i<<=1){
		w0=ksm(t==1?M0:M1,(M-1)/(i*2));
		for(j=0;j<Len;j+=i<<1)
			for(w=1,k=0;k<i;k++,w=1ll*w*w0%M){
				x=A[j+k];y=1ll*A[j+i+k]*w%M;
				A[j+k]=(x+y)%M;
				A[j+i+k]=(x-y+M)%M;
			}
	}
	if(t==1)return;
	x=ksm(Len,M-2);
	for(i=0;i<Len;i++)
		A[i]=1ll*x*A[i]%M;
}
void work(char c){
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	memset(C,0,sizeof(C));
	memset(d,0,sizeof(d));
	for(i=0;i<n;i++)
		if(s[i]==c)
			d[i]=k+1;
	for(i=1;i<n;i++)
		d[i]=max(d[i],d[i-1]-1);
	for(i=n-2;i>=0;i--)
		d[i]=max(d[i],d[i+1]-1);
	for(i=0;i<n;i++)
		A[i]=d[i]>0;
	for(i=0;i<m;i++)
		B[i]=t[i]==c;
	for(Len=1,l=0;Len<=n+m;Len<<=1,l++);
	for(i=1;i<Len;i++)
		Rs[i]=(Rs[i>>1]>>1)|((i&1)<<(l-1));
	NTT(A,1);
	NTT(B,1);
	for(i=0;i<Len;i++)
		C[i]=1ll*A[i]*B[i]%M;
	NTT(C,-1);
	for(i=0;i<Len;i++){
		//printf("%d ",C[i]);
		S[i]+=C[i];
	}
	//printf("\n");
}
int main(){
	init();
	work('A');
	work('G');
	work('C');
	work('T');
	for(i=0;i<=n+m-1;i++){
	//	printf("%d ",S[i]);
		if(S[i]==m)
			Ans++;
	}
	printf("%d",Ans);
	return 0;
}