#include<cstdio>
#include<algorithm>
using namespace std;
#define MOD 51123987
#define MAXN 2000000
char s[MAXN*2+10];
int n,len[MAXN*2+10],cnt[MAXN+1],ans,tot;
void read(){
	scanf("%d%s",&n,s);
	int i;
	s[n*2+2]='$';
	s[n*2+1]='#';
	for(i=n-1;i>=0;i--){
		s[i*2+2]=s[i];
		s[i*2+1]='#';
	}
	s[0]='@';
}
void manacher(){
	int po=1,p=1,i,j;
	for(i=1;i<=n*2;i++){
		if(i<p){
			if(i+len[2*po-i]<p){
				len[i]=len[2*po-i];
				continue;
			}
			else
				len[i]=p-i;
		}
		else
			len[i]=1;
		for(j=len[i];s[i+j]==s[i-j];j++);
		len[i]=j;
		po=i,p=i+j;
	}
	for(i=1;i<=n;i++){
		cnt[i]++,cnt[i+len[i*2]/2]--;
		tot=(tot+len[i*2]/2)%MOD;
		cnt[i]++,cnt[i+len[i*2-1]/2]--;
		tot=(tot+len[i*2-1]/2)%MOD;
	}
	for(i=1;i<=n;i++)
		cnt[i]+=cnt[i-1];
	for(i=1;i<=n;i++)
		(cnt[i]+=cnt[i-1])%=MOD;
	for(i=1;i<=n;i++){
		(cnt[i]+=cnt[i-1])%=MOD;
		ans=(ans+cnt[i-1]-cnt[i-len[i*2]/2-1])%MOD;
		if(i>1)
			ans=(ans+cnt[i-2]-cnt[i-len[i*2-1]/2-2])%MOD;
	}
}
int main()
{
	read();
	manacher();
	printf("%I64d\n",((1ll*tot*(tot-1)%MOD*((MOD+1)/2)-ans)%MOD+MOD)%MOD);
}