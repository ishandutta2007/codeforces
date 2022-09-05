// author: xay5421
// created: Sat Oct  9 18:28:56 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int brand(){return rng()&0X7FFFFFFF;}
const int N=1005;
int n,a[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	//n=1000;
	//rep(i,1,n)a[i]=brand()%1000*2+1;
	rep(i,1,n)rep(j,i+1,n)if(a[i]==a[j]){
		puts("YES");
		printf("0 %d ",a[i]);
		rep(k,1,n)if(i!=k&&j!=k){
			printf("%d ",a[k]);
		}
		exit(0);
	}
	shuffle(a+1,a+1+n,rng);
	if(n==2){
		if(a[1]!=a[2])puts("NO"),exit(0);
		else printf("YES\n%d %d\n",0,a[1]),exit(0);
	}
	auto xay_div=[&](int x,int y){
		if(y==0||x%y!=0)puts("NO"),exit(0);
		return x/y;
	};
	if(n==3){
		int t=xay_div(a[1]+a[2]+a[3],2);
		puts("YES");
		printf("%d %d %d\n",t-a[1],t-a[2],t-a[3]);
		exit(0);
	}
	int pos[3]={-1,-1,-1};
	rep(i,1,n)if(~a[i]&1)pos[0]=i;
	if(pos[0]!=-1){
		rep(i,1,n){
			rep(j,1,2)if(pos[j]==-1&&i!=pos[0]){
				pos[j]=i;
				break;
			}
		}
		int t=xay_div(a[pos[0]]+a[pos[1]]+a[pos[2]],2);
		puts("YES");
		printf("%d %d %d ",t-a[pos[0]],t-a[pos[1]],t-a[pos[2]]);
		rep(i,1,n){
			bool pd=1;
			rep(j,0,2)if(pos[j]==i)pd=0;
			if(pd){
				printf("%d ",a[i]-(t-a[pos[0]]));
			}
		}
		exit(0);
	}else{
		if(n>=50){
			static int num[4000005][4];
			static bool vis[N];
			while(1){
				static int val[4];
				rep(i,0,3){
					int x=brand()%n+1;
					while(vis[x])x=brand()%n+1;
					vis[x]=1;
					val[i]=x;
				}
				int sum=a[val[0]]+a[val[1]]+a[val[2]]+a[val[3]];
				if(num[sum][0]){
					bool flg=1;
					rep(i,0,3)if(vis[num[sum][i]])flg=0;
					if(flg){
						rep(i,0,3)vis[num[sum][i]]=1;
						puts("YES");
						int x=0;
						rep(i,0,3){
							printf("%d ",x);
							x=a[num[sum][i]]-x;
							printf("%d ",x);
							x=a[val[i]]-x;
						}
						rep(i,1,n)if(!vis[i])printf("%d ",a[i]);
						exit(0);
					}
				}
				rep(i,0,3)num[sum][i]=val[i],vis[val[i]]=0;
			}
		}else{
			int tot=0;
			while(1){
				if(((++tot)&255)==0&&1.*clock()/CLOCKS_PER_SEC>=0.95){
					puts("NO"),exit(0);
				}
				shuffle(a+1,a+1+n,rng);
				static int sum[N];
				rep(i,1,n){
					sum[i]=sum[i-1]+a[i];
				}
				rep(i,1,n/2){
					if(sum[i]==sum[i*2]-sum[i]){
						int x=0;
						puts("YES");
						rep(j,1,i){
							printf("%d ",x);
							x=a[j]-x;
							printf("%d ",x);
							x=a[j+i]-x;
						}
						rep(j,i*2+1,n)printf("%d ",a[j]);
						exit(0);
					}
				}
			}
		}
	}
	return 0;
}