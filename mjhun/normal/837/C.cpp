#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int n,a,b;
int x[256],y[256],w[256];

int main(){
	scanf("%d%d%d",&n,&a,&b);
	fore(i,0,n)scanf("%d%d",x+i,y+i),w[i]=i,x[i+n]=y[i],y[i+n]=x[i],w[i+n]=i;
	n*=2;
	int r=0;
	fore(i,0,n)fore(j,i+1,n)if(w[i]!=w[j]){
		if(max(x[i],x[j])<=a&&max(y[i],y[j])<=b)
		if(x[i]+x[j]<=a||y[i]+y[j]<=b)r=max(r,x[i]*y[i]+x[j]*y[j]);
	}
	printf("%d\n",r);
	return 0;
}