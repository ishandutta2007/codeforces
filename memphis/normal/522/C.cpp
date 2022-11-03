#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define N 100005
#define inf 0x7f7f7f7f
#define LL long long

int t,m,k,a[N],c[N],r[N];
bool vis[N],ex[N];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&k),m--;
		rep(i,1,k) scanf("%d",a+i);
		int cnt=0;
		bool flag=1;
		rep(i,1,m) scanf("%d%d",c+i,r+i);
		rep(i,1,k) vis[i]=0,ex[i]=0;
		rep(i,1,m){
			if(r[i] && flag){
				flag=0;
				rep(j,i,m) vis[c[j]]=1;
				int mn=inf;
				rep(j,1,k) if(cnt>=a[j] && !vis[j]){
					ex[j]=1;
					if(mn>a[j]) mn=a[j];
				}
				if(mn==inf){puts("Error");return 0;}
				cnt-=mn;
			}
			if(c[i]) a[c[i]]--;
			else cnt++;
		}
		rep(i,1,k) if(!ex[i] && cnt>=a[i]) ex[i]=1;
		rep(i,1,k) if(ex[i]) putchar('Y');else putchar('N');
		puts("");
	}
}