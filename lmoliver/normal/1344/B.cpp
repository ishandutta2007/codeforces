#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2020;
char s[N][N]={'\0'};
void gg(){
	puts("-1");
	exit(0);
}
int test(int sx,int sy,int dx,int dy,int n){
	int state=0;
	for(int i=0;i<n;i++){
		bool black=s[sx+dx*i][sy+dy*i]=='#';
		if(state==0){
			if(black){
				state=1;
			}
		}
		else if(state==1){
			if(!black){
				state=2;
			}
		}
		else{
			if(black){
				gg();
			}
		}
	}
	return state;
}
void ww(int x,int y);
void kk(int x,int y){
	if(s[x][y]=='#'){
		ww(x,y);
	}
}
void ww(int x,int y){
	s[x][y]='.';
	kk(x+1,y);
	kk(x-1,y);
	kk(x,y+1);
	kk(x,y-1);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	bool a=false;
	for(int i=1;i<=n;i++){
		a|=test(i,1,0,1,m)==0;
	}
	bool b=false;
	for(int i=1;i<=m;i++){
		b|=test(1,i,1,0,n)==0;
	}
	if(a^b){
		gg();
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='#'){
				ans++;
				ww(i,j);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}