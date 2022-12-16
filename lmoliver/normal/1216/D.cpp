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
const int N=200200;
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
int n;
int a[N];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	LL g=0;
	LL m=a[0];
	LL s=a[0];
	for(int i=1;i<n;i++){
		g=gcd(g,abs(a[i]-a[0]));
		m=max(m,(LL)a[i]);
		s+=a[i];
	}
	LL y=((LL)n*m-s)/g;
	cout<<y<<" "<<g<<endl;
	return 0;
}