#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1<<12;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int a[maxn],k,n,p[maxn],pos[maxn],q[maxn],sum;
void modify(int x,int y){
	ri z=pos[q[x]^a[x]];
	if(z==x)return;
	else if(z==y){
		swap(p[x],p[y]);
		pos[p[x]]=x,pos[p[y]]=y;
		return;
	}
	else{
		swap(p[x],p[z]);
		pos[p[x]]=x,pos[p[z]]=z;
		swap(q[y],q[z]);
		modify(z,y);
	}
}
signed main(){
	scanf("%d",&k);
	n=1<<k;
	for(ri i=0;i<n;++i)scanf("%d",a+i),p[i]=pos[i]=q[i]=i,sum^=a[i];
	if(sum)return puts("Fou"),0;
	for(ri i=0;i+1<n;++i)modify(i,i+1);
	puts("Shi");
	for(ri i=0;i<n;++i)printf("%d ",p[i]);
	printf("\n");
	for(ri i=0;i<n;++i)printf("%d ",q[i]);
	return 0;
}