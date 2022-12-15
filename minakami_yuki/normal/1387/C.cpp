#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
using namespace std;
const int N=103;
const int S=55;
const ull INF = -1;

int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

int G,n,m;
int a[N],k[N],b[N][N];
int l[S],c[S][S];
ull dp[N][S][S];
ull tp[S][S];
int cnt;
queue<int>q;
struct ACauto{
    int t[S][2],val[S],fail[S];
    void ins(int len,int *s){
        int now=0;
        for(int i=1;i<=len;i++){
            int v=s[i];
            if(!t[now][v]) t[now][v]=++cnt;
            now=t[now][v];
        }
        val[now]++;
    }
    void build(){
        for(int i=0;i<2;i++) 
			if(t[0][i]) {
        		fail[t[0][i]]=0;
				q.push(t[0][i]);
			}
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=0;i<2;i++) {
            	if(t[u][i]) {
					fail[t[u][i]]=t[fail[u]][i];
					q.push(t[u][i]);
				}
            	else t[u][i]=t[fail[u]][i];
			}
        }
        for(int j=0;j<=cnt;++j){
        	int flag=val[j],i=j;
        	while(i){
        		i=fail[i];
        		flag=max(flag,val[i]);
			}
			val[j]=flag;
			if(val[j]) t[j][0]=t[j][1]=j;
		}
		//for(int i=0;i<=cnt;++i) cout<<t[i][0]<<" "<<t[i][1]<<endl;
    }
}AC;

bool sol(int row){
	bool re=0;
	for(int st=0;st<=cnt;++st){
		fill_n(tp[0],S*S,INF);
		tp[0][st]=0;
		for(int it=1;it<=k[row];++it){
			int h=b[row][it];
			for(int i=0;i<=cnt;++i){
				if(tp[it-1][i]>=INF) 
					continue;
				for(int j=0;j<=cnt;++j)
					if(dp[h][i][j]<INF) 
						tp[it][j]=min(tp[it][j],tp[it-1][i]+dp[h][i][j]);
			}
		}
		for(int ed=0;ed<=cnt;++ed){
			if(dp[a[row]][st][ed]>tp[k[row]][ed]){
				dp[a[row]][st][ed]=tp[k[row]][ed];
				re=1;
			}
		}
	}
	return re;
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d%d%d",&G,&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i],&k[i]);
		for(int j=1;j<=k[i];++j){
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=1;i<=m;++i){
		scanf("%d",&l[i]);
		for(int j=1;j<=l[i];++j){
			scanf("%d",&c[i][j]);
		}
		AC.ins(l[i],c[i]);
	}
	AC.build();
	fill_n(dp[0][0],N*S*S,INF);
	for(int i=0;i<=cnt;++i){
		for(int h=0;h<2;++h){
			dp[h][i][AC.t[i][h]]=1;
		}
	}
	int flag=1,it=0;
	for(;flag&&it<G-2;++it){
		flag=0;
		for(int i=1;i<=n;++i) flag|=sol(i);
	}
//	cout<<it<<" "<<G-2<<endl;
	for(int i=2;i<G;++i) {
        ull ans=INF;
        for(int j=0;j<=cnt;++j) 
			if(!AC.val[j]){
        		ans=min(ans,dp[i][0][j]);
			}
        if(ans<INF) cout<<"NO " <<ans<<endl;
		else cout<<"YES"<<endl;
    }
    return 0;
}
/*
5 3 1
2 2 1 1
3 2 2 2
4 2 3 3
2 1 1

*/