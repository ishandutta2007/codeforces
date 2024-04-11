#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
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
int n,l; 
int a[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&l);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		long double L=0,R=l,t1,t2;
		long double vl=1,vr=1;
		long double ans=0; 
		int x=1,y=n;
		while(x<=y){
			t1=(long double)a[x]-L;
			t2=R-(long double)a[y];
			t1=t1/vl;
			t2=t2/vr;
			if(t1<t2){
				ans+=t1;
				L=a[x];
				R=R-t1*vr;
				++vl;
				++x;
			}
			else{
				ans+=t2;
				L=L+t2*vl;
				R=a[y];
				++vr;
				--y;
			}
		} 
		if(L<R){
			ans+=(R-L)/(vl+vr);
		}
		printf("%0.9Lf\n",ans);
	} 
	return 0;
}