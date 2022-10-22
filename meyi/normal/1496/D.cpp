#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int ld[maxn],mu,n,p[maxn],pos,rd[maxn];
bool flag;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",p+i);
		if(p[i]>p[i-1])ld[i]=ld[i-1]+1;
		else ld[i]=1;
	}
	for(ri i=n;i;--i)
		if(p[i]>p[i+1])rd[i]=rd[i+1]+1;
		else rd[i]=1;
	for(ri i=1;i<=n;++i){
		if(ld[i]>mu)mu=ld[i],flag=false,pos=i;
		else if(ld[i]==mu&&pos!=i)flag=true;
		if(rd[i]>mu)mu=rd[i],flag=false,pos=i;
		else if(rd[i]==mu&&pos!=i)flag=true;
	}
	if(flag)return putchar(48),0;
	if((ld[pos]&1)&&(rd[pos]&1)&&ld[pos]==rd[pos])putchar(49);
	else putchar(48);
}