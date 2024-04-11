#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

char s[5005];int n;
int f[5005][5005];
int r[5005];

int main(){
	scanf("%s",s);n=strlen(s);
	fore(i,0,n){
		int a=i,b=i+1;
		while(a>=0&&b<=n&&s[a]==s[b-1]){
			f[a][b]=1;
			a--;b++;
		}
	}
	fore(i,1,n){
		int a=i-1,b=i+1;
		while(a>=0&&b<=n&&s[a]==s[b-1]){
			f[a][b]=1;
			a--;b++;
		}
	}
	r[1]=n;
	fore(l,2,n+1){
		fore(i,0,n-l+1){
			int j=i+l;
			if(!f[i][j])continue;
			f[i][j]=min(f[i][(i+j)/2],f[(i+j+1)/2][j])+1;
			r[f[i][j]]++;
		}
	}
	for(int i=n;i>1;--i)r[i-1]+=r[i];
	fore(i,1,n+1){
		if(i>1)putchar(' ');
		printf("%d",r[i]);
	}
	puts("");
	return 0;
}