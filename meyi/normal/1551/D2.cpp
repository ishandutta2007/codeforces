#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=110;
int k,m,n,t_case;
char ans[maxn][maxn];
int main(){
	srand(time(0));
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&m,&k);
		for(ri i=1;i<=n;++i)
			for(ri j=1;j<=m;++j)
				ans[i][j]=0;
		if(m&1){
			ri mx=(m-1)*n/2;
			if(k>mx){
				puts("NO");
				continue;
			}
		}
		bool flag=false;
		if(n&1){
			if(k<m/2){
				puts("NO");
				continue;
			}
			k-=m/2;
			for(ri i=1;i<=m;++i)ans[n][i]='a'+((i-1)/2)%26;
			--n;
			if(!n){
				puts("YES");
				for(ri i=1;i<=m;++i)putchar(ans[1][i]),ans[1][i]=0;
				putchar(10);
				continue;
			}
			flag=true;
		}
		ri tmp=k%n;
		if((n-tmp)&1)puts("NO");
		else{
			puts("YES");
			for(ri i=1;i<=k;++i){
				ri c=((i-1)/n+1)*2-1,r=(i-1)%n+1;
				char ch='a'+(rand()%26);
				while(ans[r-1][c]==ch||ans[r-1][c+1]==ch||
					  ans[r][c+2]==ch||ans[r][c-1]==ch||
					  ans[r+1][c]==ch||ans[r+1][c+1]==ch)ch='a'+(rand()%26);
				ans[r][c]=ans[r][c+1]=ch;
				assert(r>=1&&r<=n&&c>=1&&c+1<=m);
			}
			for(ri i=1;i<=n;++i)
				for(ri j=1;j<=m;++j)
					if(!ans[i][j]){
						char ch='a'+(rand()%26);
						while(ans[i-1][j]==ch||ans[i][j-1]==ch||
							  ans[i][j+1]==ch||ans[i+2][j]==ch||
							  ans[i+1][j-1]==ch||ans[i+1][j+1]==ch)ch='a'+(rand()%26);
						ans[i][j]=ans[i+1][j]=ch;
						assert(i>=1&&i+1<=n&&j>=1&&j<=m);
					}
			if(flag)++n;
			for(ri i=1;i<=n;++i,putchar(10))
				for(ri j=1;j<=m;++j)
					putchar(ans[i][j]);
		}
	}
	return 0;
}