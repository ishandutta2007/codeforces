#include<bits/stdc++.h>
#define int long long
const int N=200005,mod=998244353;
using namespace std;

int dp[N][2][2][2][2][2][2];
string s;

void add(int&x,int y){
	x+=y;if(x>=mod)x-=mod;
}

void solve(){
	cin>>s;
	int n=s.size();s='0'+s;
	dp[0][0][0][0][0][0][0]=1;
	for(int i=1;i<=n;i++){
		int t=s[i]-'0';
		for(int x=0;x<=1;x++)
			for(int y=0;y<=1;y++)
				for(int z=0;z<=1;z++){
					for(int a=0;a<=1;a++){
						if(a==0&&t==0&&x==1)continue;
						for(int b=0;b<=1;b++){
							if(b==0&&t==0&&y==1)continue;
							for(int c=0;c<=1;c++){
								if(c==0&&t==0&&z==1)continue;
								for(int o=0;o<=1;o++)
								for(int p=0;p<=1;p++)
								for(int q=0;q<=1;q++){
									int A=a||x<t,B=b||y<t,C=c||z<t;
									int O=o||((x^y)==1&&(x^z)==1);
									int P=p||((y^z)==1&&(x^z)==1);
									int Q=q||((x^y)==1&&(y^z)==1);
									add(dp[i][A][B][C][O][P][Q],dp[i-1][a][b][c][o][p][q]);
								}
							}
						}
					}					
				} 
	}
	int res=0;
	for(int a=0;a<2;a++)
	for(int b=0;b<2;b++)
	for(int c=0;c<2;c++)
		add(res,dp[n][a][b][c][1][1][1]);
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}