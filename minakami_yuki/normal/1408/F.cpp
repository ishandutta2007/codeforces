#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+10;
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
int n;
int Q=0;
int L[N],R[N];
void sol(int l,int r){
	if(l==r) return;
	int mid=l+r>>1;
	sol(l,mid);
	sol(mid+1,r);
	for(int i=l,j=mid+1;i<=mid;++i,++j){
		L[++Q]=i;
		R[Q]=j;
	}
}
int main(){
	scanf("%d",&n);
	if(n==1||n==2){
		cout<<0<<endl;
		return 0;
	}
	if(n==3){
		cout<<1<<endl;
		cout<<1<<" "<<2<<endl;
		return 0;
	}
	if(n==4){
		cout<<2<<endl;
		cout<<1<<" "<<2<<endl;
		cout<<3<<" "<<4<<endl;
		return 0;
	}
	int m=1;
	while((m+m)<n) m=m+m;
	sol(1,m);
	sol(n-m+1,n);
	printf("%d\n",Q);
	for(int i=1;i<=Q;++i){
		printf("%d %d\n",L[i],R[i]);
	}
	return 0;
}