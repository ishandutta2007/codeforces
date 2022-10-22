#pragma GCC optimize(2)
#pragma GCC optimize("inline")
#pragma GCC optimize("-funroll-loops")
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,mod=998244353;
char s[MAXN];
int n;
int f[2][2][2][2][2][2],g[2][2][2][2][2][2],ans;
int main(){
	scanf("%s",s);
	n=strlen(s);
	f[1][1][1][0][0][0]=1;
	for(int i=0; i<n; i++){
		char ch=s[i]-'0';
		memset(g,0,sizeof(g));
		for(int p=0; p<2; p++)
			for(int q=0; q<2; q++)
				for(int r=0; r<2; r++)
					for(int x=0; x<2; x++)
						for(int y=0; y<2; y++)
							for(int z=0; z<2; z++)
								for(int a=0; a<=(p?ch:1); a++)
									for(int b=0; b<=(q?ch:1); b++)
										for(int c=0; c<=(r?ch:1); c++)
											(g[p&&a==ch][q&&b==ch][r&&c==ch][x|(a^b)&(a^c)][y|(a^c)&(b^c)][z|(a^b)&(b^c)]+=f[p][q][r][x][y][z])%=mod;
		memcpy(f,g,sizeof(f));
	}
	for(int p=0; p<2; p++)
		for(int q=0; q<2; q++)
			for(int r=0; r<2; r++)
				ans=(ans+f[p][q][r][1][1][1])%mod;
	printf("%d\n",ans);
	return 0;
}