#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=300300;
const int L=20;
int a[N];
int nxt[N][L];
int ne[N][L];
int n,q;
int main(){
	memset(nxt,-1,sizeof nxt);
	memset(ne,0x3f,sizeof ne);
	scanf("%d%d",&n,&q);
	int ap[L];
	memset(ap,-1,sizeof ap);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<L;j++){
			if((a[i]>>j)&1){
				if(ap[j]!=-1){
					nxt[ap[j]][j]=i;
				}
				ap[j]=i;
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<L;j++){
			if((a[i]>>j)&1){
				ne[i][j]=i;
			}
			else{
				for(int k=0;k<L;k++){
					int x=nxt[i][k];
					if(x!=-1){
						ne[i][j]=min(ne[i][j],ne[x][j]);
					}
				}
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		for(int i=0;i<L;i++){
			if(((a[y]>>i)&1)&&ne[x][i]<=y){
				puts("Shi");
				goto ok;
			}
		}
		puts("Fou");
		ok:;
	}
	return 0;
}