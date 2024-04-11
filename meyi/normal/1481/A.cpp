#include<bits/stdc++.h>
using namespace std;
#define ri register int
const int maxn=1e5+10;
int d,l,r,t,u,x,y;
char s[maxn];
inline bool judgex(int k){
	return !k||(k<0&&l>=-k)||(k>0&&r>=k);
}
inline bool judgey(int k){
	return !k||(k<0&&d>=-k)||(k>0&&u>=k);
}
int main(){
	scanf("%d",&t);
	while(t--){
		u=d=r=l=0;
		memset(s,0,sizeof s);
		scanf("%d%d%s",&x,&y,s);
		for(ri i=0;s[i];++i)
			switch(s[i]){
				case 'U':{
					++u;
					break;
				}
				case 'D':{
					++d;
					break;
				}
				case 'R':{
					++r;
					break;
				}
				case 'L':{
					++l;
					break;
				}
			}
		puts(judgex(x)&&judgey(y)?"YES":"NO");
	}
	return 0;
}