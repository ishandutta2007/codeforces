#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005,Lim=131072,P=998244353;
int n,m,pw[18][N],f[18][Lim],popcnt[Lim],ans[Lim],cq;char s[N],qwq[19];
void upd(int &x,int y){if((x+=y)>=P)x-=P;}
void updt(int msk,int c){for(int i=0;i<=17;i++)upd(f[i][msk],pw[i][c]);}
int main(){
	scanf("%d%s%d",&n,s+1,&m);
	for(int i=1;i<=n;i++)cq+=(s[i]=='?');
	for(int i=1;i<Lim;i++)popcnt[i]=popcnt[i>>1]+(i&1);
	for(int i=0;i<=17;i++)
		for(int j=0,p=1;j<=n;p=1ll*p*i%P,j++)pw[i][j]=p;
	for(int i=1;i<=n;i++){
		int l=i,r=i,cf=cq,msk=0;
		while(l&&r<=n){
			if(s[l]!='?'&&s[r]!='?'&&s[l]!=s[r])break;
			if(s[l]=='?'&&s[r]=='?')cf-=(l!=r);
			else if(s[l]=='?'||s[r]=='?')msk|=1<<(s[l]=='?'?s[r]-'a':s[l]-'a'),cf--;
			updt(msk,cf),l--,r++;
		}
	}
	for(int i=1;i<n;i++){
		int l=i,r=i+1,cf=cq,msk=0;
		while(l&&r<=n){
			if(s[l]!='?'&&s[r]!='?'&&s[l]!=s[r])break;
			if(s[l]=='?'&&s[r]=='?')cf--;
			else if(s[l]=='?'||s[r]=='?')msk|=1<<(s[l]=='?'?s[r]-'a':s[l]-'a'),cf--;
			updt(msk,cf),l--,r++;
		}
	}
	for(int b=0;b<=17;b++){
		for(int i=1;i<Lim;i<<=1)
			for(int j=0;j<Lim;j+=i<<1)
				for(int k=0;k<i;k++)upd(f[b][i+j+k],f[b][j+k]);
	}
	for(int i=0;i<Lim;i++)ans[i]=f[popcnt[i]][i];
	for(int i=1;i<=m;i++){
		scanf("%s",qwq);int k=strlen(qwq),msk=0;
		for(int j=0;j<k;j++)msk|=1<<(qwq[j]-'a');
		printf("%d\n",ans[msk]);
	}
	return 0;
}