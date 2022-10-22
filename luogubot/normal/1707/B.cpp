#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e5+10;
vector<int> a;int n;
signed main(){
	int T=read();while(T--){
		int zr=0;n=read(),a.clear();For(i,1,n)a.push_back(read());
		while(a.size()>=2){
			vector<int> tmp;if(zr)tmp.push_back(*a.begin()),zr--;
			For(i,0,a.size()-2)tmp.push_back(a[i+1]-a[i]);
			sort(tmp.begin(),tmp.end()),a.clear();
			For(i,0,tmp.size()-1)if(!tmp[i])zr++;else a.push_back(tmp[i]);
		}if(!a.empty())printf("%d\n",*a.begin());else puts("0"); 
	}
	return 0;
}