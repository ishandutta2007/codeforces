#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100000
int n,p,l[MAXN+10],r[MAXN+10],np[MAXN+10];
double ans;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
void read(){
	Read(n),Read(p);
	for(int i=1;i<=n;i++){
		Read(l[i]),Read(r[i]);
		np[i]=r[i]/p-(l[i]-1)/p;
	}
}
void solve(){
	int i;
	for(i=1;i<=n;i++)
		ans+=(1.0*np[i]*(r[i%n+1]-l[i%n+1]+1)+1.0*(r[i]-l[i]+1-np[i])*np[i%n+1])/(r[i]-l[i]+1)*2000/(r[i%n+1]-l[i%n+1]+1);
}	
int main()
{
	read();
	solve();
	printf("%.7lf",ans);
}