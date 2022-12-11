#include<bits/stdc++.h>
#define ll long long
// #define int long long
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
int n,cnt;
std::vector<int> a,b;
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int i=1,x;i<=n;i++)read(x),a.push_back(x);
	while(a.size()){
		std::sort(a.begin(),a.end());
		b.clear();
		for(int i=1;i<a.size();i++)
			if(a[i]%a[0]){
				b.push_back(a[i]);
			}
		a=b;
		// for(auto i:b)print(i,' ');puts("");
		++cnt;
	}
	print(cnt,'\n');
}