#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
char s[MAXN];
int a[MAXN];
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		scanf("%s",s+1);
		int mi=-1,mx=-1;
		for(int i=1; i<=n*2; i++){
			if(s[i]=='(') a[i]=a[i-1]+1;
			else a[i]=a[i-1]-1;
			if(a[i]<0){
				if(mi==-1) mi=i;
				mx=i;
			}
		}
		//for(int i=1; i<=n*2; i++) printf("%d ",a[i]); puts("");
		if(~mi){
			int l=1,r=n*2;
			for(int i=2; i<=mi; i++)
				if(a[i-1]>a[l-1]) l=i;
			for(int i=mx+1; i<n*2; i++)
				if(a[i]>a[r]) r=i;
			reverse(s+l,s+r+1);
			int sum=0;
			for(int i=1; i<=n*2; i++){
				if(s[i]=='(') sum++;
				else sum--;
				if(sum<0) break;
			}
			if(sum<0){
				puts("2");
				int w=0;
				for(int i=1; i<n*2; i++)
					if(a[i]>a[w]) w=i;
				printf("%d %d\n",1,max(w,1));
				printf("%d %d\n",w+1,n*2);
			}else{
				puts("1");
				printf("%d %d\n",l,r);
			}
		}else puts("0");
	}
	return 0;
}