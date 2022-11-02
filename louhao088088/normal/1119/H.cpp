#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit(x) (x&-x)
#define int long long
const int maxn=4e5+5,M=34005,mod=998244353,G=3;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,a,b,c,a2[maxn],a1[maxn],a3[maxn],x,y,z,ans[maxn],s=0;
int Pow(int x,int y){int res=1;while(y){if(y&1)res=res*x%mod;x=x*x%mod;y=y/2;}return res;}
void FWT(int *a,int n,int op){
	int s=1;if(op)s=(mod+1)/2;
	for(int i=1;i<n;i=i*2){
		int o=i*2;
		for(int j=0;j<n;j+=o){
			for(int k=0;k<i;k++){
				int x=a[j+k],y=a[j+k+i];
				a[j+k]=(x+y)*s%mod;a[i+j+k]=(x-y+mod)*s%mod;				
			}
		}
	}
}
signed main(){
	n=read(),m=read();x=read(),y=read(),z=read();int p=0;
	for(int i=1;i<=n;i++)a=read(),b=read(),c=read(),
		b^=a,c^=a,p^=a,a1[b]++,a2[c]++,a3[b^c]++;
	FWT(a1,1<<m,0),FWT(a2,1<<m,0),FWT(a3,1<<m,0);
	int s1=(x+y+z)%mod,s2=(x+y-z+mod)%mod,s3=(x-y+z+mod)%mod,s4=(x-y-z+mod*2)%mod;
//	cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl; 
	for(int i=0;i<(1<<m);i++){
		/*c1+c2+c3+c4=n
		c1+c2-c3-c4=a1
		c1+c3-c2-c4=a2
		c1+c4-c2-c3=a3
		*/
		//cout<<a1[i]<<" "<<a2[i]<<" "<<a3[i]<<endl; 
		int inv=(mod/2+1);
		int c1=(a1[i]+a2[i]+a3[i]+n)*inv%mod*inv%mod;
		//cout<<a1[i]<<" "<<a2[i]<<" "<<a3[i]<<endl;
		c1+=mod;c1%=mod;
		int c2=(n+a1[i])*inv%mod-c1+mod;c2%=mod;
		int c3=(n+a2[i])*inv%mod-c1+mod;c3%=mod;
		int c4=(n+a3[i])*inv%mod-c1+mod;c4%=mod;
		//cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<endl; 
		ans[i]=Pow(s1,c1)*Pow(s2,c2)%mod*Pow(s3,c3)%mod*Pow(s4,c4)%mod;
		//cout<<ans[i]<<endl;
	}
	FWT(ans,1<<m,1);
	for(int i=0;i<(1<<m);i++)printf("%d ",ans[i^p]);
	
}