#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d %d",&n,&m);
    	int m1=0,m2=0;
    	for(int i=1;i<=n;i++){
    		int a,b; scanf("%d %d",&a,&b);
    		m1 = max(m1, a-b);
    		m2 = max(m2, a);
    	}
    	if(!m1 && m2 < m) puts("-1");
    	else printf("%d\n",m-m2<=0?1:(m-m2)/m1+(((m-m2)%m1?1:0))+1);
    } 
}