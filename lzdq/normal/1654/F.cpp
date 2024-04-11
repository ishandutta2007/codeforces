#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<ctime>
#include<chrono>
#include<random>
using namespace std;
unsigned seed=chrono::system_clock::now().time_since_epoch().count();
mt19937 rnd(seed);
// shuffle (begin(),end(),default_random_engine(seed));
typedef long long ll;
const int MAXN=1<<18|5,k1=19491001,p1=1e9+7,k2=19260817,p2=1004535809;
int n;
ll pw1[MAXN],pw2[MAXN];
char s[MAXN];
struct Hash{
	int h1,h2,len;
};
Hash operator +(Hash a,Hash b){
	return Hash{
		(int)((a.h1*pw1[b.len]+b.h1)%p1),
		(int)((a.h2*pw2[b.len]+b.h2)%p2),
		a.len+b.len
	};
}
bool operator ==(Hash a,Hash b){
	return a.h1==b.h1&&a.h2==b.h2&&a.len==b.len;
}
Hash geth(int c){
	return Hash{c,c,1};
}
vector<Hash> f[19][MAXN];
bool cmp(int x,int y){
	if(f[0][0][x]==f[0][0][y]) return 0;
	int dif=0,p1=0,p2=0;
	for(int i=0; i<n; i++){
		Hash a(f[i+1][p1|(x>>n-i-1&1)<<i][x&(1<<n-i-1)-1]),b(f[i+1][p2|(y>>n-i-1&1)<<i][y&(1<<n-i-1)-1]);
		if(a==b){
			//printf("i %d same\n",i);
			dif|=1<<n-i-1;
			p1|=(1^(x>>n-i-1&1))<<i;
			p2|=(1^(y>>n-i-1&1))<<i;
		}else{
			//printf("i %d diff\n",i);
			p1|=(x>>n-i-1&1)<<i;
			p2|=(y>>n-i-1&1)<<i;
		}
	}
	//printf("dif %d\n",dif);
	//if(s[x^dif]==s[y^dif]) puts("err");
	return s[x^dif]<s[y^dif];
}
int ans,rev[MAXN];
int main(){
	//freopen("in2.txt","r",stdin);
	scanf("%d",&n);
	scanf("%s",s);
	pw1[0]=pw2[0]=1;
	for(int i=1; i<=1<<n; i++){
		pw1[i]=pw1[i-1]*k1%p1;
		pw2[i]=pw2[i-1]*k2%p2;
	}
	for(int i=1; i<1<<n; i++)
		rev[i]=rev[i>>1]>>1|(i&1)<<n-1;
	for(int i=0; i<1<<n; i++)
		f[n][i].push_back(geth(s[rev[i]]));
	for(int d=n-1; ~d; d--)
		for(int i=0; i<1<<d; i++){
			for(int j=0; j<1<<n-d-1; j++)
				f[d][i].push_back(f[d+1][i][j]+f[d+1][i|1<<d][j]);
			for(int j=0; j<1<<n-d-1; j++)
				f[d][i].push_back(f[d+1][i|1<<d][j]+f[d+1][i][j]);
		}
	/*
	for(int d=0; d<=n; d++)
		for(int i=0; i<1<<d; i++)
			for(int j=0; j<1<<n-d; j++){
				printf("%d %d %d ",d,i,j);
				cout<<f[d][i][j].s<<endl;
			}
		//if(cmp(p[x],ans)) ans=p[x];
	cmp(4,5);
	ans=5;
	*/
	for(int x=1; x<1<<n; x++)
		if(cmp(x,ans)) ans=x;
	for(int i=0; i<1<<n; i++)
		putchar(s[i^ans]);
	puts("");
	//printf("ans %d\n",ans);
	return 0;
}