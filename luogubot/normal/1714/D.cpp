#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=100+10;
int n,l,len[N];char t[N],s[N][N];
int f[N];
int pre[N],pos[N];
signed main(){
	int T=read();while(T--){
		memset(f,0x3f,sizeof f),f[0]=0,memset(pre,0,sizeof pre);
		scanf("%s",t+1),l=strlen(t+1);
		For(i,1,n=read())scanf("%s",s[i]+1),len[i]=strlen(s[i]+1);
		For(i,1,l){
			For(j,1,n)if(i+len[j]-1<=l){
				int fl=1;
				For(k,i,i+len[j]-1)fl&=t[k]==s[j][k-i+1];
				if(fl){
					For(k,i,i+len[j]-1){
						if(f[i-1]+1<f[k])f[k]=f[i-1]+1,pos[k]=i,pre[k]=j;
					}
				}
			}
		}if(f[l]<=l){
			cout<<f[l]<<endl;
			int now=l;
			while(now){
				cout<<pre[now]<<" "<<pos[now]<<endl;
				now=pos[now]-1;
			}
		}else puts("-1");
	}
	return 0;
}