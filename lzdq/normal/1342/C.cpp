#include<cstdio>
typedef long long ll;
const int MAXN=2e5+5;
int a,b,c,q,sum[MAXN];
ll ans;
int main(){
	int _; scanf("%d",&_);
    while(_--){
        scanf("%d%d",&a,&b);
        c=a*b;
        for(int i=1;i<c;i++)
            sum[i]=sum[i-1]+(i%b%a!=i%a%b);
		scanf("%d",&q);
        while(q--){
			ll l,r;
            scanf("%lld%lld",&l,&r);
            if(l/c==r/c){
				if(l%c) printf("%d ",sum[r%c]-sum[l%c-1]);
				else printf("%d ",sum[r%c]);
			}else{
				ll lx=l/c+1,rx=r/c-1;
				ans=sum[c-1]*(rx-lx+1)+sum[c-1]+sum[r%c];
				if(l%c) ans-=sum[l%c-1];
				printf("%lld ",ans);
				
			}
        }
		puts("");
    }
    return 0;
}
/*
int T,a,b,q,sum[50010];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&a,&b,&q);
        int m=a*b;
        for(int i=1;i<m;i++){
            sum[i]=sum[i-1];
            if((i%a)%b!=(i%b)%a) sum[i]++;
        }
        long long l,r;
        while(q--){
            scanf("%lld %lld",&l,&r);
            if(l/m==r/m){printf("%d ",sum[r%m]-((l%m==0)?0:sum[l%m-1]));continue;}
            long long lx=l/m+1,rx=r/m-1,ans=0;
            ans+=(rx-lx+1)*sum[m-1];
            ans+=sum[m-1]-((l%m==0)?0:sum[l%m-1])+sum[r%m];
            printf("%lld ",ans);
        }
        printf("\n");
    }
    return 0;
}
*/