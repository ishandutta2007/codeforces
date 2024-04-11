#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
int n,i,j,a[N],d[N],p,t[N];
long long s;
bool cmp(int x,int y){
	return a[x]<a[y];
}
void add(int x,int y){
	while(x<=n)
		t[x]+=y,x+=x&-x;
}
int min(int x,int y){
	return x<y?x:y;
}
int sum(int x){
	int s=0;
	while(x)
		s+=t[x],x-=x&-x;
	return s;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),d[i]=i,add(i,1);
	sort(d+1,d+n+1,cmp);
	for(i=j=1,p=n;i<=n;i++){
		if(a[i]>=i-1)
			add(i,-1);
		while(j<=n&&a[d[j]]<i){
			if(d[j]>i)
				add(d[j],-1);
			j++;
		}
		s+=sum(min(a[i],n));
	}
	printf("%I64d",s);
}