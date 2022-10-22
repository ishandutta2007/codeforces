#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),ans=m;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
            if(i<=m&&a[i]<=m)
                ans--;
        }
		printf("%d\n",ans);
	}
	return 0;
}