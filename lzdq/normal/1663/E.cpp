#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=105;
const char t[]="theseus";
int n;
char s[MAXN][MAXN];
bool ans;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%s",s[i]+1);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			bool ok;
			if(j+6<=n){
				ok=1;
				for(int k=0; k<7; k++)
					if(s[i][j+k]!=t[k]) ok=0;
				if(ok) ans=1;
			}
			if(i+6<=n){
				ok=1;
				for(int k=0; k<7; k++)
					if(s[i+k][j]!=t[k]) ok=0;
				if(ok) ans=1;
			}
			if(i+6<=n&&j+6<=n){
				ok=1;
				for(int k=0; k<7; k++)
					if(s[i+k][j+k]!=t[k]) ok=0;
				if(ok) ans=1;
			}
		}
	if(ans) puts("YES");
	else puts("NO");
	return 0;
}