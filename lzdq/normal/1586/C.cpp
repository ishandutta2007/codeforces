#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
int n,m,q;
char s[MAXN],t[MAXN];
int sum[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%s",s+1);
		if(i>1){
			for(int j=2; j<=m; j++)
				if(s[j-1]=='X'&&t[j]=='X') sum[j]=1;
		}
		for(int j=1; j<=m; j++)
			t[j]=s[j];
	}
	for(int i=2; i<=m; i++)
		sum[i]+=sum[i-1];
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(l==r||sum[l]==sum[r]) puts("YES");
		else puts("NO");
	}
	return 0;
}