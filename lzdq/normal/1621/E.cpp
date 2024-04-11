#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cassert>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const double eps=1e-9;
int n,m,a[MAXN];
vector<int> b[MAXN];
ll s[MAXN];
char ans[MAXN],*ch;
double ave[MAXN];
int pre[3][MAXN];
bool test2;
int main(){
	//freopen("in.txt","r",stdin);
	int _; scanf("%d",&_);
	//if(_==5) test2=1;
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		if(n>m) for(int i=1; i<=m; i++) a[i]=a[i+n-m];
		ch=ans;
		n=m;
		for(int i=1; i<=n; i++){
			int k;
			scanf("%d",&k);
			b[i].clear();
			s[i]=0;
			for(int j=1; j<=k; j++){
				int x;
				scanf("%d",&x);
				b[i].push_back(x);
				s[i]+=x;
			}
			ave[i]=(double)(s[i])/k;
		}
		sort(ave+1,ave+n+1);
		for(int i=1; i<=n; i++){
			pre[0][i]=pre[0][i-1];
			if(a[i]<ave[i]) pre[0][i]++;
			pre[1][i]=pre[1][i-1];
			if(i>1&&a[i]<ave[i-1]) pre[1][i]++;
			pre[2][i]=pre[2][i-1];
			if(i<n&&a[i]<ave[i+1]) pre[2][i]++;
			//printf("%d a %d ave %.2f pre %d %d %d\n",i,a[i],ave[i],pre[0][i],pre[1][i],pre[2][i]);
		}
		if(test2&&!_) printf("n %d\n",n);
		for(int i=1; i<=n; i++){
			double t=(double)(s[i])/b[i].size();
			int x=lower_bound(ave+1,ave+n+1,t-eps)-ave;
			assert(x>0&&x<=n);
			for(int j:b[i]){
				bool res=0;
				double v=(double)(s[i]-j)/(b[i].size()-1);
				if(v<=t){
					int y=lower_bound(ave+1,ave+n+1,v)-ave;
					assert(y>0&&y<=x);
					//y++;
					//y=min(y,x);
					//printf("1 v %.2f y %d\n",v,y);
					if(v<=a[y]&&!pre[0][y-1]&&!(pre[1][x]-pre[1][y])&&!(pre[0][n]-pre[0][x])) res=1;
					if(test2&&!res&&!_) printf("x %d y %d\n",x,y);
				}else{
					//printf("2 v %.2f y %d\n",v,y);
					//y=min(y,n);
					int y=upper_bound(ave+1,ave+n+1,v)-ave-1;
					assert(x<=y&&y<=n);
					if(v<=a[y]&&!pre[0][x-1]&&!(pre[2][y-1]-pre[2][x-1])&&!(pre[0][n]-pre[0][y])) res=1;
					if(test2&&!res&&!_) printf(" x %d y %d\n",x,y);
				}
				*ch=res+'0';
				ch++;
			}
		}
		*ch=0;
		puts(ans);
	}
	return 0;
}