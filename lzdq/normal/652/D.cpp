#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int n;
int l[MAXN],r[MAXN];
int a[MAXN],b[MAXN<<1];
inline bool cmp(int a,int b){
	return r[a]<r[b];
}
int BinSrc(int k){
	int l=1,r=n;
	while(l<r){
		const int mid=l+r>>1;
		if(b[mid]>=k) r=mid;
		else l=mid+1;
	}
	return l;
}
int rsum[MAXN<<1];
inline int Query(int w){
	int res=0;
	for(int i=w;i;i-=i&-i)
		res+=rsum[i];
	return res;
}
inline void Add(int w){
	for(int i=w;i<=n;i+=i&-i)
		rsum[i]++;
}
int ans[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",l+i,r+i),a[i]=i,b[i]=l[i];
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		int w=a[i];
		const int t=BinSrc(l[w]);
		ans[w]=i-1-Query(t-1);		//	>=l[w]
		Add(t);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}