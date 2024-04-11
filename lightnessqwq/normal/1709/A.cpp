#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int vis[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		int a,b,c,x;
		scanf("%d",&x);
		scanf("%d%d%d",&a,&b,&c);
		if(a==1||b==2||c==3||(a==2&&b==1)||(a==3&&c==1)||(b==3&&c==2))
			puts("NO");
		else puts("YES");
	}
	return 0;
}