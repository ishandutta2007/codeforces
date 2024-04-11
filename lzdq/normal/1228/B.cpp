#include<cstdio>
const int N=1005;
const int Mod=1e9+7;
int n,m,Num[N][N],Answer;
bool flag;
inline int Read(){
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
inline int Quick_Pow(int x,int k){
	int ss=1;
	for(;k;k>>=1){
		if(k&1) ss=1ll*ss*x%Mod;
		x=1ll*x*x%Mod;
	}
	return ss;
}
inline void Init(){
	n=Read();m=Read();
	for(register int i=1;i<=n;i++){
		int k=Read();
		for(register int j=1;j<=k;j++){
			if(Num[i][j]==-1) return flag=1,void();
			Num[i][j]=1;
		}
		if(Num[i][k+1]==1) return flag=1,void();
		Num[i][k+1]=-1;
	}
	for(register int i=1;i<=m;i++){
		int k=Read();
		for(register int j=1;j<=k;j++){
			if(Num[j][i]==-1) return flag=1,void();
			Num[j][i]=1;
		}
		if(Num[k+1][i]==1) return flag=1,void();
		Num[k+1][i]=-1;
	}
}
inline void Query(){
	if(flag) return puts("0"),void();
	int cnt=0;
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=m;j++)
			if(Num[i][j]==0) cnt++;
	}
	Answer=Quick_Pow(2,cnt);
	printf("%d\n",Answer);
}
int main(){
	Init();
	Query();
	return 0;
}