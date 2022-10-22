#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline void ckmax(int &x,const int &y){if(x<y)x=y;}
template<class T>inline void ckmin(int &x,const int &y){if(x>y)x=y;}
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		vector<int>b,c;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			if(i&1)b.push_back(a[i]);
			else c.push_back(a[i]);
		}
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());
		for(ri i=1;i<=n;++i){
			if(i&1)a[i]=b[i>>1];
			else a[i]=c[(i-1)>>1];
		}
		bool flag=false;
		for(ri i=1;i<n;++i)
			if(a[i]>a[i+1])
				flag=true;
		puts(flag?"NO":"YES");
	}
}