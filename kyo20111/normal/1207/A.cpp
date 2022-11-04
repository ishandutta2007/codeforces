#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,a,b,c,d,e;
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    	a/=2;
    	printf("%d\n",max(min(a,b)*d + min(a-min(a,b), c)*e, min(a,c)*e + min(a-min(a,c), b)*d));
    }
}