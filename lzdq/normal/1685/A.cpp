#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN],b[MAXN];
int main(){
	//freopen("in","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		if(n&1){
			puts("NO");
		}else{
			sort(a+1,a+n+1);
			int x=0,y=0;
			if(a[n/2]==a[n/2+1]){
				while(x<n/2&&a[n/2-x]==a[n/2]) x++;
				while(y<n/2&&a[n/2+y+1]==a[n/2]) y++;
			}
			if(x+y<n/2){
				puts("YES");
				int w=1;
				for(int i=1; i<=n; i++)
					b[i]=-1;
				for(int _=0; _<x; _++)
					b[w]=a[n/2],w+=2;
				w++;
				for(int _=0; _<y; _++)
					b[w]=a[n/2],w+=2;
				w=1;
				for(int i=1; i<=n; i+=2)
					if(b[i]==-1) b[i]=a[w++];
				w=n/2+y+1;
				for(int i=2; i<=n; i+=2)
					if(b[i]==-1) b[i]=a[w++];
				for(int i=1; i<=n; i++)
					printf("%d ",b[i]);
				puts("");
			}else if(x+y==n/2&&0){
				/*
				for(int i=1; i<=n; i+=2)
					b[i]=a[n/2];
				for(int i=2,j=1; i<=n; i+=2){
					while(a[j]==a[n/2]) j++;
					b[i]=a[j++];
				}
				puts("YES");
				for(int i=1; i<=n; i++)
					printf("%d ",b[i]);
				puts("");
				*/
			}else puts("NO");
		}

	}
	return 0;
}