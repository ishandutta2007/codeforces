#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}

int n;
bool dp[25][555],bl[25][555],ban[25][555];
int ID(int x,int y){
	return x*360+y;
} 
int f[1111111];
int Fd(int x){
	if (f[x]==x) return x;
	return f[x]=Fd(f[x]);
} 
void work(){
	n=read();
	ms(ban,0);
	ms(bl,0);
	ms(dp,0);
	F(i,0,359) dp[0][i]=1;
	F(i,1,n){
		char s;
		cin>>s;
		int r=read(),p1=read(),p2=read();
		if (s=='C'){
			for (int x=p1;x!=p2;x++,x%=360){
				ban[r][x]=1;
			}
		}
		else{
			F(j,r,p1-1) bl[j][p2]=1;
		}
	}
	F(i,0,21) F(j,0,359) f[ID(i,j)]=ID(i,j);
	F(i,0,21){
		if (i){
			F(j,0,359){
				if (!ban[i][j]){
					f[Fd(ID(i,j))]=Fd(ID(i-1,j));
				}
			}
		}
		F(j,0,359){
			if (!bl[i][j]){
				int x=ID(i,j),y=ID(i,(j+359)%360);
				f[Fd(x)]=Fd(y);
			}
		}
	}
//	F(i,1,21){
//		F(j,0,359){
//			if (!ban[i][j] && dp[i-1][j]) dp[i][j]=1; 
//		}
//		F(j,0,359){
//			if (dp[i][(j+360-1)%360] && !bl[i][j]) dp[i][j]=1;
//		}
//		F(j,0,359){
//			if (dp[i][(j+360-1)%360] && !bl[i][j]) dp[i][j]=1;
//		}
//		DF(j,359,0){
//			if (dp[i][(j+360+1)%360] && !bl[i][(j+1)%360]) dp[i][j]=1;
//		}
//		DF(j,359,0){
//			if (dp[i][(j+360+1)%360] && !bl[i][(j+1)%360]) dp[i][j]=1;
//		}
		
//		F(j,0,359){
//			if (dp[i][(j+360-1)%360] && !bl[i][j]) dp[i][j]=1;
//		}
//		F(j,0,359){
//			if (dp[i][(j+360-1)%360] && !bl[i][j]) dp[i][j]=1;
//		}
//		DF(j,359,0){
//			if (dp[i][(j+360+1)%360] && !bl[i][(j+1)%360]) dp[i][j]=1;
//		}
//		DF(j,359,0){
//			if (dp[i][(j+360+1)%360] && !bl[i][(j+1)%360]) dp[i][j]=1;
//		}
//	}
//	F(i,0,359){
//		if (dp[21][i]){
//			cout<<"YES\n";
//			return ;
//		}
//	}
	if (Fd(ID(21,0))==Fd(ID(0,0))) cout<<"YES\n"; 
	else cout<<"NO\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
2
5
C 1 180 90
C 5 250 230
C 10 150 140
C 20 185 180
S 1 20 180
6
C 1 180 90
C 5 250 230
C 10 150 140
C 20 185 180
S 1 20 180
S 5 10 141
*/