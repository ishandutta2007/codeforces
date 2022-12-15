#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+10;
const LL INF=1e18;
const LL P=1e9+7;
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
void add(LL &x,LL y){
	x+=y;if(x>=P)x-=P;
}
int n;
int a[N];
int cnt=0;
int l[N],r[N];
int v2[N],v3[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	int it2=1,it3=1;
	int h=0;
	for(int i=1;i<=n;++i){
		//cout<<i<<endl;
		if(a[i]==0) continue;
		if(a[i]==1){
			if(v2[i]) continue;
			++h;
			++cnt;
			l[cnt]=h;
			r[cnt]=i;
			continue;
		}
		if(a[i]==2){
			while((it2<=n)&&(it2<=i||v2[it2]||v3[it2]||a[it2]!=1)) ++it2;
			if(it2>n){
				puts("-1");
				return 0;
			}
			++h;
			++cnt;l[cnt]=h;r[cnt]=i;
			++cnt;l[cnt]=h;r[cnt]=it2;
			v2[it2]=1;
			continue;
		}
		if(a[i]==3){
			while((it3<=n)&&(it3<=i||v2[it3]||v3[it3]||a[it3]==0)) ++it3;
			if(it3>n){
				puts("-1");
				return 0;
			}
			++h;
			++cnt;l[cnt]=h;r[cnt]=i;
			++cnt;l[cnt]=h;r[cnt]=it3;
			v3[it3]=1;
			continue;
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i){
		printf("%d %d\n",l[i],r[i]);
	}
    return 0;
}