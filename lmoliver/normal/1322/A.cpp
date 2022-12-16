#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1001001;
int n;
char a[N];
int main(){
	scanf("%d",&n);
	scanf("%s",a);
	int c=0,ans=0;
	for(int i=0;i<n;i++){
		if(a[i]=='('){
			ans+=c++<0?1:0;
		}
		else{
			ans+=--c<0?1:0;
		}
	}
	if(c!=0){
		ans=-1;
	}
	printf("%d\n",ans);
	return 0;
}