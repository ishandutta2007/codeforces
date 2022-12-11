#include <bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
int n,m;
std::string s,t,ans;
bool check(){
    for (int i=0;i<n;i++){
        if(s[i]>ans[i])return 0;
        if(s[i]<ans[i])return 1;
	}return 1;
}
void dfs(int i){if(t[i]=='9')dfs(i-1),t[i]='0';else t[i]++;}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
    read(n),read(m),std::cin>>s;
    for(int i=0;i<m;i++)t+=s[i];
    while(1){ans+=t; if(ans.size()>n)break;}
    ans.resize(n);
    if(check()){print(n,'\n'),std::cout<<ans<<std::endl;return 0;}
    t=ans="";
    for(int i=0;i<m;i++)t+=s[i];
    dfs(m-1);
    while(1){ans+=t; if(ans.size()>n)break;}
    ans.resize(n);
    if(check()){print(n,'\n'),std::cout<<ans<<std::endl;return 0;}
    return 0;
}