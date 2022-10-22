#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10;
int n;
struct node{
	int c,l,r;
	bool operator < (const node &x) const {
		return r<x.r;
	}
}a[N];
int del[N];
struct sta1{
	int L,R,id;
	bool operator < (const sta1 &x) const {
		return L<x.L;
	}
};
struct sta2{
	int L,R,id;
	bool operator < (const sta2 &x) const {
		return R<x.R;
	}
};priority_queue<sta1> q1;priority_queue<sta2> q2;
void clr(){
	while(!q1.empty()&&del[q1.top().id])q1.pop();
	while(!q2.empty()&&del[q2.top().id])q2.pop();
}
signed main(){
	int T=read();while(T--){
		n=read();For(i,1,n)a[i].c=read(),a[i].l=read(),a[i].r=read(),del[i]=0;int ans=n;
		while(!q1.empty())q1.pop();while(!q2.empty())q2.pop();
		sort(a+1,a+1+n);For(i,1,n){
			clr();//printf("%d [%d,%d]\n",a[i].c,a[i].l,a[i].r);
			if(a[i].c==0){
				int L=a[i].r,R=-1;
				while(!q2.empty()){
					clr();if(q2.empty())break;
					if(a[i].l<=q2.top().R){
						L=max(L,q2.top().L),R=max(R,q2.top().R),del[q2.top().id]=1,ans--,q2.pop();
					}else break;
				}q1.push((sta1){L,R,i}),q2.push((sta2){L,R,i});
			}else{
				int R=a[i].r,L=-1;
				while(!q1.empty()){
					clr();if(q1.empty())break;
					if(a[i].l<=q1.top().L){
						L=max(L,q1.top().L),R=max(R,q1.top().R),del[q1.top().id]=1,ans--,q1.pop();
					}else break;
				}q1.push((sta1){L,R,i}),q2.push((sta2){L,R,i});
			}//puts("done");
		}printf("%d\n",ans);
	}
	return 0;
}