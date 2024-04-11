#include<cstdio>
const int N=8000002;
typedef long long ll;
int n,i;
ll a[N],b[N],Ans;
struct Tire{
	int ch[N][2],sz[N],cnt=1;
	void Insert(ll x,int k){
		for(int i=1,j=40;j>=0;j--){
			if(!ch[i][x>>j&1])
				ch[i][x>>j&1]=++cnt;
			i=ch[i][x>>j&1];
			sz[i]+=k;
		}
	}
	void Query(ll x){
		ll s=0;
		for(int i=1,j=40;j>=0;j--){
			if(sz[ch[i][~x>>j&1]])
				i=ch[i][~x>>j&1],s|=1ll<<j;
			else
				i=ch[i][x>>j&1];
		}
		if(s>Ans)
			Ans=s;
	}
}T;
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",a+i);
		b[i]=a[i];
	}
}
void work(){
	T.Insert(0,1);
	for(i=1;i<=n;i++){
		a[i]^=a[i-1];
		T.Insert(a[i],1);
	}
	T.Query(0);
	for(i=n;i;i--){
		b[i]^=b[i+1];
		T.Insert(a[i],-1);		
		T.Query(b[i]);
	}
	printf("%lld",Ans);
}
int main(){
	init();
	work();
	return 0;
}