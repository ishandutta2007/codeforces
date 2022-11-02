#include<cstdio>
const int N=400002;
int n,i,k,a[N],p[N],w[N],h[N],t[N],v[N],x,y,z,d[N],id[N],s[N],l,r,mid;
long long len[N];
void dfs(int i){
	for(int j=h[i];j;j=t[j]){
		d[v[j]]=d[i]+1;
		id[d[v[j]]]=v[j];
		len[d[v[j]]]=len[d[i]]+w[j];
		dfs(v[j]);
		s[i]+=s[v[j]];
	}
	s[p[i]]++;
	l=1;r=d[i];
	while(l<r){
		mid=l+r>>1;
		if(len[d[i]]-len[mid]<=a[i])
			r=mid;
		else
			l=mid+1;
	}
	s[id[r-1]]--;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=2;i<=n;i++){
		scanf("%d%d",p+i,&z);
		x=p[i];y=i;
		t[++k]=h[x];
		h[x]=k;
		v[k]=y;
		w[k]=z;
	}
	d[1]=1;
	id[1]=1;
	dfs(1);
	for(i=1;i<=n;i++)
		printf("%d ",s[i]);
//	while(1);
}