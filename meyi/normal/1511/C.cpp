#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
int a[maxn],add[51],m,n,pos[51],t_case;
int main(){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			if(!pos[a[i]])pos[a[i]]=i;
		}
		memset(add,0,sizeof add);
		while(m--){
			int q;
			scanf("%d",&q);
			printf("%d ",pos[q]+add[q]);	
			for(ri i=1;i<51;++i)
				if(i!=q&&pos[q]+add[q]>pos[i]+add[i])
					++add[i];
			pos[q]=1,add[q]=0;
		}
	return 0;
}