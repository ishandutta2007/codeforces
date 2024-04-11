#include <bits/stdc++.h>
using namespace std;
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)

__int64 a[10][20][10],b[10][20][10],c[20];

int maxdigit(__int64 x){
	return x? max(maxdigit(x/10), (int)(x%10)):0;
}

int main() {
	//freopen("in.txt","r",stdin);
	int i,j,k,x,y,z,l;
	__int64 n,m,tot;

	for(l=0;l<19;l++) {
		for(x=9;x>=0;x--) {
			for(y=0;y<=9;y++) {
				tot=0;
				if(!l) {
					if(!x) {
						if(y) {b[x][l][y]=1;a[x][l][y]=0;}
						else {b[x][l][y]=0;a[x][l][y]=0;}

					}
					else if(x>y) {
						a[x][l][y]=y+10-x;
						b[x][l][y]=1;
					}
					else {
						a[x][l][y]=10-x;
						b[x][l][y]=2;
					}
				}
				else {
					tot=0;m=y;
					for(j=9;j>=0;j--) {
						tot+=b[Max(x,j)][l-1][m];
						m=a[Max(x,j)][l-1][m];
					}
					a[x][l][y]=m;
					b[x][l][y]=tot;
				}
			}
		}
	}
	scanf("%I64d",&n);
	m=n%10;
	__int64 K=n/10;
	__int64 res=0;
	int len=0;
	while(1){
		while(K%10!=9 && K){
			res+=b[maxdigit(K)][len][m];
			m=a[maxdigit(K)][len][m];
			K--;
		}
		if(!K) {
			res+=b[0][len][m];
			break;
		}
		K/=10;
		len++;
	}
	printf("%I64d\n", res);
	return 0;
}