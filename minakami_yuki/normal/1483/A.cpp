#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
const int INF=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}

int n,m; 

int K[N];

vector<int> V[N];

int t[N];
int a[N];

void MAIN(){
    scanf("%d%d",&n,&m);
    int x;
    for(int i=1;i<=n;++i) t[i]=0;
    for(int i=1;i<=m;++i){
    	scanf("%d",&K[i]);
    	V[i].clear();
    	for(int j=1;j<=K[i];++j){
    		scanf("%d",&x);
    		V[i].push_back(x);
		}
		if(K[i]==1){
			++t[x];
			a[i]=x;
		}
	}
	int lim=(m+1)>>1;
	for(int i=1;i<=n;++i){
		if(t[i]>lim){
			puts("NO");
			return;
		}
	} 
	puts("YES");
	for(int i=1;i<=m;++i){
		if(K[i]>1){
			if(t[V[i][0]]==lim){
				++t[V[i][1]];
				a[i]=V[i][1];
			}
			else{
				++t[V[i][0]];
				a[i]=V[i][0];
			}
		}
	}
	for(int i=1;i<=m;++i) printf("%d ",a[i]);
	puts("");
	return;
}

int main(){
    int ttt=read();
    while(ttt--) MAIN();
    return 0;
}