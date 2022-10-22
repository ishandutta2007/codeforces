#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int INF=0x3fffffff;
int n;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		int s1,s2,s3,x=INF,y=0;
		for(int i=1; i<=n; i++){
			int l,r,c;
			scanf("%d%d%d",&l,&r,&c);
			if(l<x){
				x=l;
				s1=c;
				s3=INF;
			}else if(l==x) s1=min(s1,c);
			if(r>y){
				y=r;
				s2=c;
				s3=INF;
			}else if(r==y) s2=min(s2,c);
			if(l==x&&r==y) s3=min(s3,c);
			printf("%d\n",min(s1+s2,s3==INF?INF*2:s3));
		}
	}
	return 0;
}