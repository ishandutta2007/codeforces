#include<cstdio>
#include<vector>
using namespace std;
const int N=1200002;
int T,n,i,D,a[N],b[N],c[N],t[N],tmp;
vector<int>p[N];
int max(int x,int y){
	return x>y?x:y;
}
void Update(int x,int y){
	for(x+=D;x;x>>=1)
		t[x]=max(t[x],y);
}
int Query(int x,int y){
	int s=0;
	for(x+=D-1,y+=D+1;x^y^1;x>>=1,y>>=1){
		if(~x&1)s=max(s,t[x^1]);
		if(  y&1)s=max(s,t[y^1]);
	}
	return s;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		tmp=1;
		for(D=1;D<n+2;D<<=1);
		for(i=1;i<D*2;i++)
			t[i]=0;
		for(i=1;i<=n;i++)
			p[i].clear();
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
			scanf("%d",b+i);
		for(i=n;i;i--)
			p[b[i]].push_back(i);
		for(i=1;i<=n;i++){
			if(p[a[i]].empty()){
				tmp=0;
				break;
			}
			c[i]=p[a[i]].back();
			p[a[i]].pop_back();
		}
		for(i=1;i<=n&&tmp;i++){
			if(Query(1,a[i]-1)>c[i]){
				tmp=0;
				break;
			}
			Update(a[i],c[i]);
		}
		printf("%s\n",tmp?"YES":"NO");
	}
}