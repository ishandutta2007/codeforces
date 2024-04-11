#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep2(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn=1000010;
int lastans=0,N;
int p[maxn][31],pos[maxn][31];
inline int f(int &x){
	x=(x^lastans)%N+1;
}
void add(int i,int x){
	rep(j,0,30) p[i][j]=p[i-1][j],pos[i][j]=pos[i-1][j];
    int ti=i;
	rep2(j,30,0){
        if(x&(1<<j)){
            if(!p[i][j]) { p[i][j]=x; pos[i][j]=ti; break; }
            if(pos[i][j]<ti) swap(p[i][j],x),swap(pos[i][j],ti);
            x^=p[i][j];
        }
    }
}
void MAIN(){
    int Q,L,R;lastans=0;
    scanf("%d",&N);
	memset(p,0,sizeof p);
	memset(pos,0,sizeof pos);
    rep(i,1,N) {
        int x;scanf("%d",&x);
		add(i,x);
    }
    scanf("%d",&Q);
    rep(i,1,Q) {
	   	int type=0;
//		scanf("%d",&type);
    	if(type==1){
    		int x;
    		scanf("%d",&x);
			f(x);add(++N,x);
			continue;
		}
        scanf("%d%d",&L,&R);
//        f(L);f(R);
		if(L>R)swap(L,R);
        int res=0;
        rep2(j,30,0) if(pos[R][j]>=L&&(res^p[R][j])>res) res^=p[R][j];
        printf("%d\n",res);lastans=res;
    }
}
int main(){
	int t=1;//scanf("%d",&t);
	while(t--)MAIN();
	return 0;
}