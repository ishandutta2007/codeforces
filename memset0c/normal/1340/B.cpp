#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool mrk=0;
	while(!isdigit(c))mrk^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(mrk)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}

const int N=3e3+10,tab[]={119,18,93,91,58,107,111,82,127,123};
int n,k,a[N],ans[N];
bool mrk[N][N];
char s[N];

inline void solved(){
	for(int j=0;j<n;j++)printf("%d",ans[j]);
	putchar('\n'),exit(0);
}

void dfs(int i,int x) {
	if(x>k||mrk[i][x])return;
	mrk[i][x]=1;
	if(i==n){
		if(x==k)solved();
		return;
	}
	for(int j=9;j>=0;j--){
		ans[i]=j;
		if((tab[j]&a[i])==a[i])dfs(i+1,x+__builtin_popcount(tab[j]^a[i]));
	}
}

int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),read(k);
	for(int i=0;i<n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=7;j++)a[i]=a[i]*2+(s[j]-'0');
	}
	dfs(0,0);
	printf("-1\n");
}