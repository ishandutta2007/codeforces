#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main(){
    scanf("%d",&t);
    for(int u=1; u<=t; u++){
    	scanf("%d %d", &n, &m);
    	int m1=0, m2=0;
    	for(int i=1; i<=n; i++){
    		int a,b;
    		scanf("%d %d", &a, &b);
    		m1=max(m1, a-b);
    		m2=max(m2, a);
    	}
    	if(!m1&&m2<m)printf("-1\n");
    	else printf("%d\n", m-m2<=0?1:(m-m2)/m1+(((m-m2)%m1?1:0))+1);
    }
}