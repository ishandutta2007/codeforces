#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=1e6+5;
typedef long long ll;
int n,a[MAXN],c[MAXN];
double rsum[MAXN];
double f[MAXN],ans[MAXN];
int top,stk[MAXN][2];
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i),rsum[i]=rsum[i-1]+a[i];
	for(int i=1; i<=n; i++){
		if(i==1){
			top=1;
			stk[1][0]=stk[1][1]=1;
		}else{
			while(top&&(rsum[i]-rsum[stk[top][1]])/(i-stk[top][1])<=(rsum[stk[top][1]]-rsum[stk[top][0]-1])/(stk[top][1]-stk[top][0]+1))
				top--;
			stk[top+1][0]=stk[top][1]+1;
			stk[top+1][1]=i;
			top++;
		}
	}
	for(int i=1;i<=top;i++){
		double f=(rsum[stk[i][1]]-rsum[stk[i][0]-1])/(stk[i][1]-stk[i][0]+1);
		for(int j=stk[i][0];j<=stk[i][1];j++) printf("%.9lf\n",f);
	}
	return 0;
}