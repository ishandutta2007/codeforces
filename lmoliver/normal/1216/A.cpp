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

const int N=1001001;
int n;
char s[N];
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	int ans=0;
	for(int i=0;i<n;i+=2){
		if(s[i]==s[i+1]){
			ans++;
			s[i]=s[i]^'a'^'b';
		}
	}
	cout<<ans<<endl;
	cout<<s<<endl;
	return 0;
}