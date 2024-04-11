#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=60;
int a,ans,c[3],m,n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);m=n/3;
		memset(c,0,sizeof c);
		while(n--)scanf("%d",&a),++c[a%3];
		ans=0;
		while(c[0]!=m||c[1]!=m||c[2]!=m){
			if(c[0]>m)ans+=c[0]-m,c[1]+=c[0]-m,c[0]=m;
			if(c[1]>m)ans+=c[1]-m,c[2]+=c[1]-m,c[1]=m;
			if(c[2]>m)ans+=c[2]-m,c[0]+=c[2]-m,c[2]=m;
		}
		printf("%d\n",ans);
	}
	return 0;
}