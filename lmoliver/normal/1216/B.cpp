#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#if (!defined(__cplusplus) || __cplusplus > 201103)
/**
 * Use scanner in c++14, c++17 or c++20!
 */
template<class T>
struct Scanner{
	int value;
	Scanner(){
		value=0;
		int ch;
		while(isdigit(ch=getchar())){
			value=value*10+(ch^'0');
		}
	}
};
Scanner<int> qaq;
#else
#endif
const int N=1111;
int n;
int a[N];
bool s[N]={false};
int ans[N];
LL tot=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int v=-1;
		int vv=-1;
		for(int j=1;j<=n;j++){
			if(!s[j]&&a[j]>vv){
				vv=a[j];
				v=j;
			}
		}
		ans[i]=v;
		s[v]=true;
		tot+=(i-1)*vv+1;
	}
	cout<<tot<<endl;
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	printf("\n");
	return 0;
}