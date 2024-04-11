#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100009;
int n,a[N],cnt[N*2],mn[N*2],cmn[N*2],ans=1; bool npr[2*N];
void pr(){
	npr[1]=1;
	for(int i=2;i<=N*2-10;i++){
		if(!npr[i]){
			for(int j=i;j<=(N*2-10)/i;j++)
				if(!npr[i*j]) npr[i*j]=1;
		}
	}
}
int qp(int a,int b){
    return (b==0?1:(b%2?qp(a*a,b/2)*a:qp(a*a,b/2)));
}
signed main(){
	scanf("%lld",&n);
	pr();
	memset(mn,0x3f,sizeof(mn)),memset(cmn,0x3f,sizeof(cmn));
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		for(int j=1;j<=sqrt(a[i]);j++){
			if((a[i]%j==0)&&(!npr[j])){
				cnt[j]++;
				int tmp=a[i],tot=0;
				while(tmp%j==0){
					tot++,tmp/=j;
				}
				if(tot<=mn[j]) cmn[j]=mn[j],mn[j]=tot;
				else if(tot<cmn[j]) cmn[j]=tot;
			}
			if((a[i]%j==0)&&(!npr[a[i]/j])&&(a[i]/j!=j)){
				cnt[a[i]/j]++;
				int tmp=a[i],tot=0;
				while(tmp%(a[i]/j)==0){
					tot++,tmp/=(a[i]/j);
				}
				if(tot<=mn[a[i]/j]) cmn[a[i]/j]=mn[a[i]/j],mn[a[i]/j]=tot;
				else if(tot<cmn[a[i]/j]) cmn[a[i]/j]=tot;
			}
		}
	}
	for(int i=2;i<=N*2-10;i++){
		if((!npr[i])&&cnt[i]==n) ans*=qp(i,cmn[i]);
		else if(!npr[i]&&cnt[i]==n-1) ans*=qp(i,mn[i]);
	}
	printf("%lld",ans);
	return 0;
}