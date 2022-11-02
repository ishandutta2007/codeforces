#include<cstdio>
const int N=1005;
int n,m,q;
int cnt,nowx,nowy,in;
bool flg[N][N];
inline int Read(){
	char ch;
	int f=1;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void print(const int x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(const int x,const char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline void Add(const int x,const int y){
	cnt++;
	nowx++;
	if(nowx==n+1){
		nowy++;
		nowx=1;
	}
	if(flg[nowx][nowy]) in++;
	//printf("x=%d y=%d nowx=%d nowy=%d\n",x,y,nowx,nowy);
	if(y<nowy||(y==nowy&&x<=nowx)) in++;
	flg[x][y]=1;
	return ;
}
inline void Sub(const int x,const int y){
	cnt--;
	if(y<nowy||(y==nowy&&x<=nowx)) in--;
	flg[x][y]=0;
	if(flg[nowx][nowy]) in--;
	nowx--;
	if(nowx==0){
		nowy--;
		nowx=n;
	}
	return ;
}
inline void Init(){
	nowx=0,nowy=1;
	n=Read();m=Read();q=Read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char ch;
			while((ch=getchar())!='*'&&ch!='.');
			if(ch=='*') Add(i,j);
		}
	//printf("%d %d\n",nowx,nowy);
	return ;
}
inline void Work(const int x,const int y){
	if(flg[x][y]) Sub(x,y);
	else Add(x,y);
	//printf("%d %d\n",nowx,nowy);
	//printf("cnt=%d in=%d\n",cnt,in);
	Print(cnt-in);
	return ;
}
int main(){
	for(Init();q;q--){
		int x=Read();
		int y=Read();
		Work(x,y);
	}
	return 0;
}