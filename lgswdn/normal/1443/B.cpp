#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9;

int T,n,a,b,lst,d[N],cnt,f[N];
char c[N];

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%s",&a,&b,c+1);
		n=strlen(c+1);
		lst=cnt=0;
		rep(i,1,n) {
			if(c[i]=='1'&&(c[i-1]=='0'||i==1)) {
				cnt++;
				d[cnt]=(i==1 ? 0 : i-lst-1);
				lst=i;
			}
			else if(c[i]=='1') lst=i;
		}
		f[1]=a;
		rep(i,2,cnt) f[i]=min(f[i-1]+d[i]*b,f[i-1]+a);
		printf("%d\n",f[cnt]);
	}
	return 0;
}