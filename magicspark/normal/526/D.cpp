#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int n,k;
char s[1000005];
int pre[1000005];
void kmp(){
	pre[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j&&s[j+1]!=s[i])j=pre[j];
		if(s[j+1]==s[i])j++;
		pre[i]=j;
	}
}
inline int test(int x){
	int len=x-pre[x];
	int down=x/len,up=(x+len-1)/len;
	int r=down/k,l=(up+k)/(k+1);
	return l<=r;
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	kmp();
	for(int i=1;i<=n;i++)printf("%c",'0'+test(i));
	printf("\n");
	return 0;
}