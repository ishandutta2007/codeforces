#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=1e5+5;
int n;
multiset<int> x,y;
int main(){
	int T=read();
	while(T--){
		n=read();x.clear(),y.clear();
		for(int i=1;i<=2*n;i++){
			int a=read(),b=read();
			if(!a) y.insert(abs(b));
			else x.insert(abs(a));
		}
		double ans=0;
		for(int i=1;i<=n;i++){
			auto it1=(--x.end()),it2=--(y.end());
			ans+=sqrt(1ll*(*it1)*(*it1)+1ll*(*it2)*(*it2));
			x.erase(it1);y.erase(it2);
		}
		printf("%.12lf\n",ans);
	}
	return 0;
}