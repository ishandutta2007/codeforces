#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100100;
void answer(bool isTokitsukazeWinner){
	puts(isTokitsukazeWinner?"tokitsukaze":"quailty");
	exit(0);
}
int n,k;
char s[N];
int l0[N],r0[N],l1[N],r1[N];
bool in(int l,int x,int r){
	return l<=x&&x<=r;
}
bool cr(int l,int r,char x){
	int dr0=min(x==0?l:INT_MAX,in(l,r0[1],r)?r0[r+1]:r0[1]);
	int dr1=min(x==1?l:INT_MAX,in(l,r1[1],r)?r1[r+1]:r1[1]);
	int dl0=max(x==0?r:-1,in(l,l0[n],r)?l0[l-1]:l0[n]);
	int dl1=max(x==1?r:-1,in(l,l1[n],r)?l1[l-1]:l1[n]);
	return dl0-dr0+1<=k||dl1-dr1+1<=k;
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	l0[0]=-1;
	for(int i=1;i<=n;i++)l0[i]=s[i]=='0'?i:l0[i-1];
	l1[0]=-1;
	for(int i=1;i<=n;i++)l1[i]=s[i]=='1'?i:l1[i-1];
	r0[n+1]=INT_MAX;
	for(int i=n;i>=1;i--)r0[i]=s[i]=='0'?i:r0[i+1];
	r1[n+1]=INT_MAX;
	for(int i=n;i>=1;i--)r1[i]=s[i]=='1'?i:r1[i+1];
	if(l0[n]==-1||l1[n]==-1||l0[n]-r0[1]+1<=k||l1[n]-r1[1]+1<=k){
		answer(true);
	}
	for(int i=1;i+k-1<=n;i++){
		if(!cr(i,i+k-1,0)||!cr(i,i+k-1,1)){
			puts("once again");
			exit(0);
		}
	}
	answer(false);
	return 0;
}