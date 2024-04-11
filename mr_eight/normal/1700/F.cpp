#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
#define pii pair<double,int>
#define ll long long
using namespace std;
inline int read(){
	bool fu=false;int x=0;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')fu=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch^'0');
		ch=getchar();
	}
	return fu?-x:x;
}
int n,a[2][200002],b[2][200002],staa[2][200002],stab[2][200002],cnta[200002],cntb[200002];
ll ans;
int main(){
	cin>>n;
	F(i,0,1)F(j,1,n)a[i][j]=read();
	F(i,0,1)F(j,1,n)b[i][j]=read();
	F(i,1,n){
		F(j,0,1)if(a[j][i]&&b[j][i])a[j][i]=b[j][i]=0;
		F(j,0,1)if(a[j][i]&&cntb[j])ans+=i-stab[j][cntb[j]--],a[j][i]=0;
		F(j,0,1)if(b[j][i]&&cnta[j])ans+=i-staa[j][cnta[j]--],b[j][i]=0;
		F(j,0,1)if(a[j][i]&&cntb[!j])ans+=i-stab[!j][cntb[!j]--]+1,a[j][i]=0;
		F(j,0,1)if(a[j][i])staa[j][++cnta[j]]=i;
		F(j,0,1)if(b[j][i]&&cnta[!j])ans+=i-staa[!j][cnta[!j]--]+1,b[j][i]=0;
		F(j,0,1)if(b[j][i])stab[j][++cntb[j]]=i;
	}
	if(!cnta[0]&&!cnta[1]&&!cntb[0]&&!cntb[1])cout<<ans;
	else cout<<-1;
	return 0;
}