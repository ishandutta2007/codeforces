#include<bits/stdc++.h>
using namespace std;
#define int long long
const int sg[]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
int vis[10000001];
main(){
    int n;
    cin>>n;
	int num=n-((int)sqrt(n))+1;
    int ans=num&1;
	for(int x=2,cnt=0;x*x<=n;x++,cnt=0)
    if(!vis[x]){
		for(int y=x;y<=n;y*=x,cnt++)
		if(y*y<=n)vis[y]=1;
		else num--,ans^=1;
		ans^=sg[cnt];
	}
	puts(ans?"Vasya":"Petya");
}