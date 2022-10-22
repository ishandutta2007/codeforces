#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline void ckmax(int &x,const int &y){if(x<y)x=y;}
template<class T>inline void ckmin(int &x,const int &y){if(x>y)x=y;}
int m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i){
			if(i==1||i==n){
				for(ri j=1;j<=m;++j){
					if((j&1)&&(m%2!=0||j!=m-1))putchar(49);
					else if(j==m)putchar(49);
					else putchar(48);
				}
			}
			else{
				if((i&1)&&(n%2!=0||i!=n-1))putchar(49);
				else if(i==n)putchar(49);
				else putchar(48);
				for(ri j=2;j<m;++j)putchar(48);
				if((i&1)&&(n%2!=0||i!=n-1))putchar(49);
				else if(i==n)putchar(49);
				else putchar(48);
			}
			putchar(10);
		}
		putchar(10);
	}
}