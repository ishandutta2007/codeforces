#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=2e5+10;
char s[N];
long long ans;
int n,sqn,lst,a[N],b[N],sum[N],pre[N],nxt[N];
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	scanf("%s",s+1),n=strlen(s+1),sqn=sqrt(n);
	for(int i=1;i<=n;i++)a[i]=s[i]-'0';
	lst=0;
	for(int i=1;i<=n;i++)if(a[i])pre[i]=lst,lst=i;
	lst=n+1;
	for(int i=n;i>=1;i--)if(a[i])nxt[i]=lst,lst=i;
	for(int i=1;i<=n;i++)if(a[i]){
		for(int j=i,k=1;j!=n+1&&k<=n/sqn+10;j=nxt[j],k++){
			int min=j-i+1,max=(nxt[j]-1)-(pre[i]+1)+1;
			// printf("%d[%d] %d[%d] : %d %d\n",i,pre[i],j,nxt[j],min,max);
			for(int t=std::max(sqn+1,min%k?min/k+1:min/k);t<=max/k;t++){
				ans+=std::min(std::min(t*k-min+1,max-t*k+1),std::min(i-pre[i],nxt[j]-j));
				// printf("%d : %d\n",t,std::min(t*k-min+1,std::min(i-pre[i],nxt[j]-j)));
			}
		}
	}
	std::cerr<<clock()/(double)CLOCKS_PER_SEC<<std::endl;
	// print(ans,'\n');
	for(int c=0;c<sqn;c++){
		// printf("=== %d ===\n",c);
		for(int i=1;i<=n;i++)b[i]=a[i]?c:-1;
		// for(int i=1;i<=n;i++)print(a[i]," \n"[i==n]);
		// for(int i=1;i<=n;i++)print(b[i]," \n"[i==n]);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+b[i];
			ans+=(sum[i]==0);
		}
		std::sort(sum+1,sum+n+1);
		// for(int i=1;i<=n;i++)print(sum[i]," \n"[i==n]);
		for(int i=1,j=1;i<=n;i=j){
			for(;j<=n&&sum[i]==sum[j];j++);
			// printf("%d %d\n",i,j);
			ans+=(long long)(j-i)*(j-i-1)/2;
		}
		// print(ans,'\n');
	}
	print(ans,'\n');
	std::cerr<<clock()/(double)CLOCKS_PER_SEC<<std::endl;
}