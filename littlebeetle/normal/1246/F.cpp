#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100102,D=26,K=19;
typedef long long ll;
int n,i,j,k,cl[N],cr[N],L[N],R[N],pre[N][D],nxt[N][D];
int T,cnt[N],num,fl[K][N],fr[K][N],mxr[N],s[N];
ll Ans,sl[K][N],sr[K][N];
char S[N];
void init(){
	scanf("%s",S+1);
	while(S[n+1])n++;
	for(register int i=1;i<=n;i++) {
		s[i]=S[i]-97;
		cl[i]=cr[i]=i;
		fl[0][i]=n;
		fr[0][i]=0;
	}
	for(register int i=0;i<D;i++){
		pre[0][i]=1;
		nxt[n+1][i]=n;
	}
	for(register int i=1;i<=n;i++){
		for(register int j=0;j<D;j++) 
			pre[i][j]=pre[i-1][j];
		L[i]=pre[i][s[i]];
		pre[i][s[i]]=i;
	}
	for(register int i=n;i;i--){
		for(j=0;j<D;j++) 
			nxt[i][j]=nxt[i+1][j];
		R[i]=nxt[i][s[i]];
		nxt[i][s[i]]=i;
	}
	for(register int i=1;i<=n;i++) {
		sort(pre[i],pre[i]+D);
		sort(nxt[i],nxt[i]+D);
	}	
}
void work(){
	for(register int T=0;T<D;T++) {
		for(register int i=1;i<=n;i++) {
			fl[0][i]=min(fl[0][i],L[nxt[i][T]]);
			fr[0][i]=max(fr[0][i],R[pre[i][D-T-1]]);
			sl[0][i]=i-1;
			sr[0][i]=n-i;
		}
		for(register int j=0;j+1<K;j++)
			for(register int i=1;i<=n;i++) {
				fl[j+1][i]=fl[j][fl[j][i]];
				fr[j+1][i]=fr[j][fr[j][i]];
				sl[j+1][i]=sl[j][i]+sl[j][fl[j][i]];
				sr[j+1][i]=sr[j][i]+sr[j][fr[j][i]];
			}
		for(register int i=1,j=1;i<=n;i++) {
			while(j<=n&&num+!cnt[s[j]]<=T+1) {
				num+=!cnt[s[j]]++,
				++j;
			}
			mxr[i]=j-1,
			num-=!--cnt[s[i]];
		}
		for(register int i=1;i<=n;i++){
			for(register int j=K-1;j>=0;j--)
				if(mxr[fl[j][cl[i]]]>=fr[j][cr[i]]){
					Ans+=sl[j][cl[i]]+sr[j][cr[i]],
					cl[i]=fl[j][cl[i]],
					cr[i]=fr[j][cr[i]];
				}
			if(mxr[cl[i]]>=cr[i]){
				Ans+=sl[0][cl[i]]+sr[0][cr[i]],
				cl[i]=fl[0][cl[i]],
				cr[i]=fr[0][cr[i]];
			}
		}
	}
	printf("%lld",Ans);
}
int main(){
	init();
	work();
	return 0;
}