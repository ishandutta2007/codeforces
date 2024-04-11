#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 16
using namespace std;
int n,f[1<<MAXN][120+10],bl[MAXN+10],r[MAXN+10],b[MAXN+10],sumr,sumb,ans;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
void read(){
	Read(n);
	char s[20];
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		Read(r[i]),Read(b[i]);
		sumr+=r[i];
		sumb+=b[i];
		bl[i]=*s=='B';
	}
}
void solve(){
	int i,t=1<<n,j,s,cb,cr;
	memset(f,0xff,sizeof f);
	f[0][0]=0;
	for(s=0;s<t;s++){
		cb=cr=0;
		for(i=1;i<=n;i++)
			if(s&(1<<(i-1))){
				if(bl[i])
					cb++;
				else
					cr++;
			}
		for(i=1;i<=n;i++)
			if(!(s&(1<<(i-1)))){
				int tr=min(cr,r[i]),tb=min(cb,b[i]);
				for(j=0;j<=120;j++)
					if(f[s][j]!=-1)
						f[s|(1<<(i-1))][j+tr]=max(f[s|(1<<(i-1))][j+tr],f[s][j]+tb);
			}
	}
	ans=0x7fffffff;
	for(i=0;i<=120;i++)
		if(f[(1<<n)-1][i]!=-1)
			ans=min(ans,max(sumr-i,sumb-f[(1<<n)-1][i]));
	printf("%d\n",ans+n);
}
int main()
{
	read();
	solve();
}