#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		vector<int>b,r;
		scanf("%s",s+1);
		for(ri i=1;i<=n;++i)(s[i]=='B'?b:r).push_back(i);
		bool flag=false;
		sort(b.begin(),b.end(),[&](const int &x,const int &y){return a[x]<a[y];});
		for(ri i=0,j=1;i<b.size();++i,++j)
			if(a[b[i]]<j)
				flag=true;
		sort(r.begin(),r.end(),[&](const int &x,const int &y){return a[x]>a[y];});
		for(ri i=0,j=n;i<r.size();++i,--j)
			if(a[r[i]]>j)
				flag=true;
		puts(flag?"NO":"YES");
	}
	return 0;
}