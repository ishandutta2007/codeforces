#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=3e5+10,LG=19,inf=1e18;
int n,m,a[N],f[LG][N];
multiset<int> s;vector<int> pos[N],op[N];
int lst[N],pre[N],nxt[N];map<int,int> mp;
inline void gmax(int &a,int b){(a<b)&&(a=b);}
void build(){For(j,1,LG-1)For(i,1,n-(1<<j)+1)f[j][i]=max(f[j-1][i],f[j-1][i+(1<<j-1)]);}
int get(int l,int r){int p=__lg(r-l+1);return max(f[p][l],f[p][r-(1<<p)+1]);}
signed main(){
	int TTT=read();while(TTT--){
		n=read(),m=read();For(i,1,n)f[0][i]=0,pre[i]=nxt[i]=0,pos[i].clear(),op[i].clear();s.clear(),mp.clear();int idx=0;
		For(i,1,n){int x=read();if(!mp[x])mp[x]=++idx;a[i]=mp[x];pos[a[i]].push_back(i);}
		memset(lst,0,sizeof lst);For(i,1,n)pre[i]=(lst[a[i]]?lst[a[i]]:0),lst[a[i]]=i;
		memset(lst,0,sizeof lst);Rof(i,n,1)nxt[i]=(lst[a[i]]?lst[a[i]]:0),lst[a[i]]=i;
		For(i,1,m){int l=read(),r=read();gmax(f[0][l],r);}build(); 
		For(i,1,n){
			int l=pre[i]+1,r=i,R=get(l,r);//*it:[pre[i]+1,i] 
			if(R>=r){
				auto it=--upper_bound(pos[a[i]].begin(),pos[a[i]].end(),R);
				if(it!=pos[a[i]].begin())
					it=prev(it),op[1].push_back(*it),op[r+1].push_back(-*it);
			}if(!nxt[i])continue;l=i+1,r=nxt[i];
			if(R>=r){
				auto it=--upper_bound(pos[a[i]].begin(),pos[a[i]].end(),R);
				op[l].push_back(*it),op[r+1].push_back(-*it);
			}if(get(1,i)>=nxt[i])op[nxt[i]+1].push_back(inf);
		}int ans=1e18;For(l,1,n){
			sort(op[l].begin(),op[l].end()),reverse(op[l].begin(),op[l].end()); 
			for(auto v:op[l])if(v>0)s.insert(v);else s.erase(s.find(-v));
//			cout<<"i = "<<l<<endl;for(auto v:s)cout<<v<<" ";puts("OKOK");
			if(s.size())ans=min(ans,max(0ll,*--s.end()-l+1));else ans=0;
		}cout<<ans<<endl;
	}
	return 0;
}