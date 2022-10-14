#include<bits/stdc++.h>
using namespace std;
int const N=22,K=360;
int t,n,c[N][K],s[N][K],f[N][K];
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		memset(c,0,sizeof c);
		memset(s,0,sizeof s);
		memset(f,0,sizeof f);
		for(cin>>n;n--;){
			char op;int a,b,p;
			cin>>op>>a>>b>>p;
			if(op=='C'){
				if(b>p){
					for(int i=b;i<K;i++)c[a][i]=1;
					for(int i=0;i<p;i++)c[a][i]=1;
				}else{
					for(int i=b;i<p;i++)c[a][i]=1;
				}
			}else{
				for(int i=a;i<b;i++)s[i][p]=1;
			}
		}
		for(int i=0;i<K;i++)
			f[1][i]=1;
		for(int k=0;k<180;k++){
			for(int r1=1;r1<=20;r1++){
				for(int i=0;i<K;i++)
					if(!c[r1][i])
						f[r1+1][i]|=f[r1][i],f[r1][i]|=f[r1+1][i];
				for(int t=2;t--;)
					for(int i=0;i<K;i++)
						if(!s[r1][(i+1)%K])
							f[r1+1][(i+1)%K]|=f[r1+1][i];
				for(int t=2;t--;)
					for(int i=K;i;i--)
						if(!s[r1][i%K])
							f[r1+1][i-1]|=f[r1+1][i%K];
			}
			for(int r1=20;r1;r1--){
				for(int i=0;i<K;i++)
					if(!c[r1][i])
						f[r1+1][i]|=f[r1][i],f[r1][i]|=f[r1+1][i];
				for(int t=2;t--;)
					for(int i=0;i<K;i++)
						if(!s[r1-1][(i+1)%K])
							f[r1][(i+1)%K]|=f[r1][i];
				for(int t=2;t--;)
					for(int i=K;i;i--)
						if(!s[r1-1][i%K])
							f[r1][i-1]|=f[r1][i%K];
			}
		}
		int flg=0;
		for(int i=0;i<K;i++)
			flg|=f[21][i];
		cout<<(flg?"YES\n":"NO\n");
	}
}