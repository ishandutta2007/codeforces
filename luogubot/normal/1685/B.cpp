#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10;
char s[N];vector<int> qa,qb;
bool cmp(int a,int b){return a>b;}
signed main(){
	int T=read();while(T--){qa.clear(),qb.clear();
		int a=read(),b=read(),c=read(),d=read();scanf("%s",s+1);int n=strlen(s+1);
		if(n!=a+b+2*c+2*d){puts("NO");continue;}
		int A=0,lst=1,all=0;For(i,1,n){
			A+=s[i]=='A';
			if(s[i]==s[i-1]){
				if(i-1-lst){
					if(i-1-lst&1){
						//len
						if(s[lst]=='A')qa.push_back(i-lst>>1);
						else qb.push_back(i-lst>>1); 
//						printf("{%d,%d} ",lst,i-1); 
					}else all+=(i-lst>>1);
				}
				lst=i;
			}
		}//[lst,n]
		if(lst<n)if(n-lst&1){
			if(s[lst]=='A')qa.push_back(n-lst+1>>1);
			else qb.push_back(n-lst+1>>1); 
		}else all+=(n-lst+1>>1);
		sort(qa.begin(),qa.end()),sort(qb.begin(),qb.end());int t=0,u=0;
		for(int v:qa){
//			printf("(%d) ",v);
			if(t+v<=c)t+=v;
			else u+=t+v-c-1,t=c;
		}for(int v:qb){
//			printf("<%d> ",v);
			if(u+v<=d)u+=v;
			else t+=u+v-d-1,u=d;
		}//printf("[%d,%d] [%d,%d] {%d}\n",t,c,u,d,all);
		puts((A!=a+c+d||min(t,c)+min(u,d)+all<c+d||t+all<c||u+all<d)?"NO":"YES");
	}
	return 0;
}