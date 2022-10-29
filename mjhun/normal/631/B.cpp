#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

int n,m,k;

int r[5005];
int c[5005];
int rt[5005];
int ct[5005];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i){
		int t,j,a;
		scanf("%d%d%d",&t,&j,&a);
		if(t==1){
			rt[j]=i;
			r[j]=a;
		}
		else {
			ct[j]=i;
			c[j]=a;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(j>1)putchar(' ');
			printf("%d",(rt[i]>ct[j])?r[i]:c[j]);
		}
		puts("");
	}
	return 0;
}