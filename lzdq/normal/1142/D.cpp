#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=1e5+5;
int n;
char s[MAXN];
int to[11][10];
int f[MAXN][11];
ll ans;
int main(){
	memset(to,-1,sizeof(to));
	for(int i=0,k=0; i<11; k+=i,i++)
		for(int j=0; j<i; j++)
			to[i][j]=(k+j+10)%11;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1; i<=n; i++){
		s[i]-='0';
		for(int j=0; j<11; j++)
			if(~to[j][s[i]]) f[i][to[j][s[i]]]+=f[i-1][j];
		if(s[i]>0) f[i][s[i]]++;
		for(int j=0; j<11; j++)
			ans+=f[i][j];
	}
	printf("%lld\n",ans);
	return 0;
}