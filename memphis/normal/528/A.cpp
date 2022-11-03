#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define LL long long
#define inf 0x7f7f7f7f
#define P 1000000007
#define N 200005

map<int,int> H,V;
int w,h,n,x,av[N],ah[N];
char opt;

int findkth(int *c,int k){
	int ans=0,cnt=0;
	for (int i=20;i>=0;--i){
		ans+=1<<i;
		if (ans>=200001||cnt+c[ans]>=k)ans-=1<<i;
			else cnt+=c[ans];
	}
	return ans+1;
}

void modify(int *a,int x){
	for(int j=x;j<=200001;j+=j&-j) a[j]++;
}

int getans(int *a,int x){
	int ans=0;
	for(int j=x;j;j-=j&-j) ans+=a[j];
	return ans;
}

int main(){
	scanf("%d%d%d",&w,&h,&n);
	V[w]++;
	H[h]++;
	modify(av,1);
	modify(av,w+1);
	modify(ah,1);
	modify(ah,h+1);
	
	while(n--){
		opt=getchar();
		while(opt!='H' && opt!='V') opt=getchar();
		scanf("%d",&x);
		if(opt=='H'){
			x++;
			int y=getans(ah,x);
			int l=findkth(ah,y),r=findkth(ah,y+1);
			modify(ah,x);
			H[r-l]--;
			if(H[r-l]==0) H.erase(r-l);
			H[x-l]++;
			H[r-x]++;
		}
		if(opt=='V'){
			x++;
			int y=getans(av,x);
			int l=findkth(av,y),r=findkth(av,y+1);
			modify(av,x);
			V[r-l]--;
			if(V[r-l]==0) V.erase(r-l);
			V[x-l]++;
			V[r-x]++;
		}
		int a=(--H.end())->first,b=(--V.end())->first;
		printf("%I64d\n",(LL)a*b);
	}
}