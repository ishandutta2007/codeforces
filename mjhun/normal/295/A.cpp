#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,m,k;
ll a[100005];
int l[100005],r[1000005],d[1000005];
int q[100005];
ll s[100005];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,n)scanf("%lld",a+i);
	fore(i,0,m)scanf("%d%d%d",l+i,r+i,d+i),l[i]--;
	fore(i,0,k){
		int x,y;
		scanf("%d%d",&x,&y);x--;
		q[x]++;q[y]--;
	}
	int w=0;
	fore(i,0,m)w+=q[i],s[l[i]]+=1LL*d[i]*w,s[r[i]]-=1LL*d[i]*w;
	ll z=0;
	fore(i,0,n){
		if(i)putchar(' ');
		z+=s[i];
		printf("%lld",a[i]+z);
	}
	puts("");
	return 0;
}