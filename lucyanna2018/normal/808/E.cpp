#include<bits/stdc++.h>
using namespace std;
struct Node{
	int w,c;
} a[111111];
bool cmp(const Node&x,const Node&y){
	return (long long int)x.c*y.w > (long long int)y.c*x.w;
}
const int magic = 55;
int n,m;
int w[4][111111],lw[4];
long long int w2[4][222];int lw2[4];
int main(){
	int id;
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
		scanf("%d%d",&a[i].w,&a[i].c);
	sort(a,a+n,cmp);
	long long int add = 0;
	for(int i=0; i<n; i++){
		if(m >= magic){
			int W = a[i].w;
			m -= W;
			add += a[i].c;
			w[W][lw[W]++] = a[i].c;
		}else{
			id = i;
			break;
		}
	}
	for(int W=1; W<=3; W++){
		int d = min(10, lw[W]);
		for(int i=1; i<=d; i++){
			m += W;
			add -= w[W][lw[W] - i];
			w2[W][++lw2[W]] = w[W][lw[W] - i];
		}
		lw[W] -= d;
	}
	for(int i=id; i<n; i++){
		int W = a[i].w;
		if(lw2[W] < m){
			w2[W][++lw2[W]] = a[i].c;
		}
	}
	for(int W=1; W<=3; W++){
		sort(w2[W]+1,w2[W]+lw2[W]+1);
		reverse(w2[W]+1,w2[W]+lw2[W]+1);
		for(int i=1; i<=lw2[W]; i++)
			w2[W][i] += w2[W][i-1];
	}
	long long int res=0;
	for(int i=0; i<=lw2[1]; i++)
	for(int j=0; j<=lw2[2]; j++)
	for(int k=0; k<=lw2[3]; k++)
		if(i+j*2+k*3<=m){
			res = max(res, w2[1][i] + w2[2][j] + w2[3][k]);
		}
	printf("%I64d\n",res + add);
	return 0;
}