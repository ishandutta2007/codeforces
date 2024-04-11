#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int N=2e5+10;
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
int n,m,cnt=1;
int du[N],b[N],p[N];
LL a[N];
queue<int> Q;
LL ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%I64d",&a[i]);
	for(int i=1;i<=n;++i) {
		scanf("%d",&b[i]);
		if(b[i]!=-1)du[b[i]]++;
	}
	for(int i=1;i<=n;++i) if(!du[i]) Q.push(i);
	int l=1,r=n,x;
	while(!Q.empty()){
		x=Q.front();Q.pop();
		ans+=a[x];
		if(a[x]<0){
			p[r]=x;--r;
			if(b[x]!=-1){
				--du[b[x]];
				if(!du[b[x]]) Q.push(b[x]);
			}
		}
		else{
			p[l]=x;++l;
			if(b[x]!=-1){
				a[b[x]]+=a[x];
				--du[b[x]];
				if(!du[b[x]]) Q.push(b[x]);
			}
		}
	}
	printf("%I64d\n",ans);
	for(int i=1;i<=n;++i) printf("%d ",p[i]);puts("");
	return 0;
}