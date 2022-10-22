#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,cr[N],cc[N],bx[N],by[N];
void addx(int x,int k){for(;x<=n;x+=x&-x)bx[x]+=k;}
void addy(int x,int k){for(;x<=n;x+=x&-x)by[x]+=k;}
int queryx(int x){int res=0;for(;x;x-=x&-x)res+=bx[x];return res;}
int queryy(int x){int res=0;for(;x;x-=x&-x)res+=by[x];return res;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,op,x,y,x2,y2;i<=m;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);
			if((++cr[x])==1)addx(x,1);
			if((++cc[y])==1)addy(y,1);
		}
		else if(op==2){
			scanf("%d%d",&x,&y);
			if((--cr[x])==0)addx(x,-1);
			if((--cc[y])==0)addy(y,-1);
		}
		else{
			scanf("%d%d%d%d",&x,&y,&x2,&y2);
			printf(queryx(x2)-queryx(x-1)==x2-x+1||queryy(y2)-queryy(y-1)==y2-y+1?"Yes\n":"No\n");
		}
	}
	return 0;
}