#include<cstdio>
#include<algorithm>
#include<cstring>
#include<random>
using namespace std;
mt19937 rnd(random_device{}());
typedef long long ll;
const int MAXN=3e5+5;
int n,p[MAXN],f[MAXN],g[MAXN],q[MAXN],d[MAXN];
char s[MAXN];
int top,stk[MAXN];
inline bool Check(int j,int i){
	return j>=i-p[i]&&f[j-1]>=i-p[i];
}
int main(){
	//freopen("in","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",p+i);
		top=0;
		f[0]=1;
		for(int i=1; i<=n; i++){
			q[i]=i+p[i];
			f[i]=f[i-1];
			d[i]=1;
			if(f[i-1]>i) f[i]=max(f[i],q[i]+1);
			if(i>1&&Check(i-1,i)){
				int l=1,r=top;
				while(l<r){
					int mid=l+r>>1;
					if(Check(stk[mid],i)) r=mid;
					else l=mid+1;
				}
				//printf("stkl %d\n",stk[l]);
				if(q[stk[l]]+1>f[i]){
					f[i]=q[stk[l]]+1;
					d[i]=0;
					g[i]=stk[l];
				}
			}
			if(p[i]&&f[i-1]>=i-p[i]&&f[i]<i){
				f[i]=i;
				d[i]=2;
			}
			while(top&&q[stk[top]]<=q[i]) top--;
			stk[++top]=i;
			//printf("%d f %d g %d d %d\n",i,f[i],g[i],d[i]);
		}
		if(f[n]>n){
			puts("YES");
			for(int i=1; i<=n; i++)
				s[i]=rnd()&1?'L':'R';
			int w=n;
			while(w>0){
				//printf("w %d\n",w);
				if(d[w]==1) s[w]='R',w--;
				else if(d[w]==0){
					s[w]='L';
					s[g[w]]='R';
					w=g[w]-1;
				}else{
					s[w]='L';
					w--;
				}
			}
			s[n+1]=0;
			puts(s+1);
		}else puts("NO");
	}
	return 0;
}