#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1111;

int n;
int r[N];
int c[N];
int rr[N],cc[N];

#define x1 ____1
#define x2 ____2
#define y1 ____3
#define y2 ____4

int m=0;
int x1[N],y1[N],x2[N],y2[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
		rr[r[i]]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		cc[c[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int ri,ci;
		for(int j=i;j<=n;j++){
			if(r[j]==i)ri=j;
			if(c[j]==i)ci=j;
		}
		if(ri!=i||ci!=i){
			m++;
			swap(r[i],r[ri]);
			swap(c[i],c[ci]);
			x1[m]=y2[m]=i;
			y1[m]=ci;
			x2[m]=ri;
		}
	}
	printf("%d\n",m);
	for(int i=1;i<=m;i++){
		printf("%d %d %d %d\n",x1[i],y1[i],x2[i],y2[i]);
	}
	return 0;
}