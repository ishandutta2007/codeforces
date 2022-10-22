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
const int N=4e5+10;
int n,d12,d13,d23;
#define pi pair<int,int>
#define fi first
#define se second
vector<pi> e;
#define add(x,y) e.push_back(pi(x,y))
signed main(){
	int T=read();while(T--){
		e.clear();
		n=read(),d12=read(),d23=read(),d13=read();
		int idx=3,fl=0;
		if(d13==d12+d23){//123
			int x=d12,y=d23;
			if(x==1){
				add(1,2);
			}else{
				idx++,add(1,idx);
				For(i,1,x-2)idx++,add(idx-1,idx);
				add(idx,2);
			}
			if(y==1){
				add(2,3);
			}else{
				idx++,add(2,idx);
				For(i,1,y-2)idx++,add(idx-1,idx);
				add(idx,3);
			}
			For(i,idx+1,n)add(1,i);
		}else if(d23==d13+d12){//213
			int x=d12,y=d13;
			if(x==1){
				add(2,1);
			}else{
				idx++,add(2,idx);
				For(i,1,x-2)idx++,add(idx-1,idx);
				add(idx,1);
			}
			if(y==1){
				add(1,3);
			}else{
				idx++,add(1,idx);
				For(i,1,y-2)idx++,add(idx-1,idx);
				add(idx,3);
			}
			For(i,idx+1,n)add(1,i);
		}else if(d12==d13+d23){//132
			int x=d13,y=d23;
			if(x==1){
				add(1,3);
			}else{
				idx++,add(1,idx);
				For(i,1,x-2)idx++,add(idx-1,idx);
				add(idx,3);
			}
			if(y==1){
				add(3,2);
			}else{
				idx++,add(3,idx);
				For(i,1,y-2)idx++,add(idx-1,idx);
				add(idx,2);
			}
			For(i,idx+1,n)add(1,i);
		}else{
			int x2=d12+d13-d23;
			if(x2&1)puts("NO"),fl=1;
			else{
				int x=x2/2,y=d12-x,z=d23-y;
				if(x<0||y<0||z<0||x+y==0||x+z==0||y+z==0)puts("NO"),fl=1;
				else{
					add(1,++idx);For(i,1,d12-2)idx++,add(idx-1,idx);
					add(idx,2);
					int h=3+x;
					if(z==1)add(h,3);
					else{
						For(i,1,z-1)idx++,add(h,idx),h=idx;
						add(h,3);
					}
					For(i,idx+1,n)add(1,i);
				}
			}
		}
		if(!fl){
			if(idx<=n){puts("YES");for(auto v:e)printf("%d %d\n",v.fi,v.se);}
			else puts("NO");
		}
	}
	return 0;
}