#include <bits/stdc++.h>
#define LL long long
using namespace std;
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
int n,m;
struct P{
	int x,y;
}a[N],b[N];
int res[1000000+1000];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&b[i].x,&b[i].y);
	}
	int ans=INF;
	for(int i=0;i<=1000000+10;++i) res[i]=0; 
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i].x>b[j].x||a[i].y>b[j].y) continue;
			res[b[j].x-a[i].x]=max(res[b[j].x-a[i].x],b[j].y-a[i].y+1);
		}
	}
	for(int i=1000000+10;i>=0;--i){
		res[i]=max(res[i+1],res[i]);
		ans=min(ans,res[i]+i);
	}
	cout<<ans<<endl;
	return 0;
}