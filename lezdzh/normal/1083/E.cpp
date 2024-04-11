#include<cstdio>
#include<algorithm>
using namespace std;

struct jx{int x,y;long long c;}a[1000001];
bool operator<(jx u,jx v){
	return u.x<v.x;
}
long long f[1000001];
int s[1000002];
long long js(int i,int j){
	return -a[i].c+1ll*a[i].x*a[i].y-1ll*a[i].y*a[j].x+f[j];
}
long long sgn(long long o){
	return o>0?1:o<0?-1:0;
}
long long cj(int p,int q,int i){
	if(a[q].x-a[i].x==0)return sgn(f[q]-f[i])*sgn(a[p].x-a[i].x);
	if(a[p].x-a[i].x==0)return -sgn(f[p]-f[i])*sgn(a[q].x-a[i].x);
	long long w1=(f[q]-f[i])/(a[q].x-a[i].x),w2=(f[p]-f[i])/(a[p].x-a[i].x);
	if(w1!=w2)return w1-w2;
	w1=(f[q]-f[i])%(a[q].x-a[i].x)*(a[p].x-a[i].x),w2=(f[p]-f[i])%(a[p].x-a[i].x)*(a[q].x-a[i].x);
	return w1-w2;
}
//long long ff[1000001];
int main(){
	int n;
	scanf("%d",&n);
	//n=500000;
	for(int i=1;i<=n;i++)
		scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].c);
		//a[i].x=rand()%1000000000+1,
		//a[i].y=rand()%1000000000+1,
		//a[i].c=rand()%1000000000+1;
	sort(a+1,a+n+1);
/*	for(int i=1;i<=n;i++){
		ff[i]=1ll*a[i].x*a[i].y-a[i].c;
		for(int j=1;j<i;j++)
			ff[i]=max(ff[i],js(i,j)+ff[j]);
	}*/
	long long ans=0;
	s[++s[0]]=0;
	for(int i=1;i<=n;i++){
		int l=1,r=s[0];
		while(l!=r){
			int mid=l+r>>1;
			if(js(i,s[mid])>=js(i,s[mid+1]))r=mid;
			else l=mid+1;
		}
		f[i]=js(i,s[l]);
		while(s[0]>1&&cj(i,s[s[0]],s[s[0]-1])<=0)s[0]--;
		s[++s[0]]=i;
/*		if(f[i]!=ff[i]){
			for(int i=1;i<=n;i++)
				printf("%d %d %d\n",a[i].x,a[i].y,a[i].c);
			while(1);
		}
*/		ans=max(ans,f[i]);
	}
	printf("%lld\n",ans);
}