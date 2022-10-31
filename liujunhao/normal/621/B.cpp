#include<cstdio>
#include<algorithm>
#define MAXN 200000
#define MAXR 1000
using namespace std;
int n,m,x[MAXN+10],y[MAXN+10],cnt2[MAXR*2+1],cnt1[MAXR*2+1];
long long ans;
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
int main()
{
	int i;
	Read(n);
	for(i=1;i<=n;i++){
		Read(x[i]),Read(y[i]);
		cnt1[x[i]-y[i]+MAXR]++;
		cnt2[x[i]+y[i]]++;
	}
	for(i=1;i<=2*MAXR;i++)
		ans+=cnt1[i]*(cnt1[i]-1)/2+cnt2[i]*(cnt2[i]-1)/2;
	printf("%I64d",ans);
}