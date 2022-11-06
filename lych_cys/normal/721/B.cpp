#include<bits/stdc++.h>
#define ll long long
#define N 105
using namespace std;

int n,m,len[N]; char s[N][N],s0[N]; int q[N];
bool ok(int x){
	int i,t=strlen(s0+1);
	if (len[x]!=t)return 0;
	for (i=1; i<=t; i++) if (s[x][i]!=s0[i])return 0;return 1;
}
bool cmp(int x,int y){ return len[x]<len[y]; }
int solve(int x){
	int t=(x-1)/m*5+x; return t;
}
int main(){
	scanf("%d%d",&n,&m);
	int i;
	for (i=1; i<=n; i++){
		scanf("%s",s[i]+1); len[i]=strlen(s[i]+1);
	}
	for (i=1; i<=n;i++)q[i]=i;sort(q+1,q+n+1,cmp);
	scanf("%s",s0+1);
	for (i=1; i<=n; i++) if (ok(i)) break;
	//	cout<<i<<endl;
	int j,k,t=len[i];
	//for (i=1; i<=n; i++) cout<<q[i]<<endl;
	for (i=1; i<=n; i++) if (len[q[i]]==t){ j=i; break;}
	for (i=n; i; i--) if (len[q[i]]==t){ k=i; break; }
	//cout<<j<<' '<<k<<endl;
	printf("%d %d\n",solve(j),solve(k));
	return 0;
}