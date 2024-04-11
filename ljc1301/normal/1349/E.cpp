#include <bits/stdc++.h>
using namespace std;
// 1: exist: if 2~n none, 1 knows
//           else 1 don't know => 2~n exist
//    none: all knows
// 1~i round exist, i+1~n none => i knows
//    -> i+1~n knows
// t[i]=(i black)?sum(j,j>=i and j black):(t[pre_black]+1)
// ? ? x ? ? x ... <=>
// ? ? _ ? ? x ... and given _ not pre-black (1~x only 1 black)
typedef long long ll;
const int maxn=200005;
int n,c[maxn],pre[maxn],ne[maxn],ne0[maxn],pre1[maxn],s[maxn]; // i+1~ne0[i] white; last can be pre-black(given white)
ll t[maxn];
// bool vis[maxn]; // can be pre-black?
bool vis[maxn]; // can be black?
inline ll sum(int x) { return (x*(x+1ll))>>1; }
inline /*void*/bool solve(int l,int r,ll t)
{
    int i,j;
    // fprintf(stderr,"solve %d %d %lld\n",l,r,t);
    for(i=0;i<=r-l+1;i++)
        if(sum(l+i-1)-sum(l-1)<=t && t<=sum(r)-sum(r-i))
            break;
    // assert(i<=r-l+1);
    if(i>r-l+1) return false;
    for(j=l;j<=r;j++)
        if(i && t-j<=sum(r)-sum(r-i+1))
            t-=j,c[j]=1,i--;
    assert(!t);
    return true;
}
inline void solve()
{
    int i,j,k/*,ne1*/,L; // next black
    ll l,r;
    for(i=0;i<n;i++) scanf("%lld",&t[n-i]);
    for(i=1,j=0;i<=n;i++)
    {
        /*scanf("%lld",&t[i]),*/c[i]=0; // vis[i]=1;
        if(t[i])
        {
            if(j && !pre[j] && t[j]==t[i]) pre[i]=0/*,vis[j]=0*/;
            else pre[i]=j;
            ne[pre[i]]=j=i,ne0[i]=i;
        }
    }
    if(!j) return;
    t[n+1]=0,pre[n+1]=j,ne[j]=n+1/*,vis[n+1]=vis[0]=1*/,vis[n+1]=1,pre1[n+1]=-1;
    for(i=ne[ne[0]];i<=n;i=ne[i])
        if(t[i]==t[pre[i]])
            ne0[pre[i]]=i,pre[ne[i]]=pre[i],ne[pre[i]]=ne[i];
    for(i=pre[n+1]/*,ne1=n+1*/;pre[i];i=pre[i])
        if(t[i]>t[pre[i]])
        {
            assert(t[i]==t[pre[i]]+1),c[pre[i]]=1; // solve(i+1,ne1-1,t[i]-t[ne[i]]-(pre[i]+1)),ne1=pre[i];
            pre1[i]=pre[i],vis[i]=0;
        }
        else // pre-black in pre[i]+1~i (as large as possible) add(min(i,pre[i]+2)~i)
        {
            // k=-1,L=min(i,pre[i]+2);
            // for(j=0;j<=ne1-1-ne0[i];j++) // #black in ne0[i]+1~ne1-1
            // {
            //     // l=sum(i+j)-sum(i),r=sum(ne1-1)-sum(ne1-1-j);
            //     // l=t[i]-t[ne[i]]-l,r=t[i]-t[ne[i]]-r,swap(l,r); // +(l~r)
            //     l=(t[i]-t[ne[i]])-(sum(ne1-1)-sum(ne1-1-j)),r=(t[i]-t[ne[i]])-(sum(ne0[i]+j)-sum(ne0[i]));
            //     l=max(l,(ll)L),r=min(r,(ll)(i-(ne0[i]!=i && pre[i]==i-1)));
            //     if(l<=r) k=max(k,(int)r);
            // }
            // assert(k!=-1);
            // if(k<i || ne0[i]!=i) k--;
            // assert(pre[i]<k && k<=i);
            // c[k]=1,solve(i+1,ne1-1,t[i]-t[ne[i]]-(k+(k<i))),ne1=k;
            if(pre1[ne[i]]==i) { vis[i]=1,pre1[i]=-1; continue; }
            vis[i]=0,pre1[i]=-1;
            if(vis[ne[i]])
                for(j=0;j<=ne[i]-1-ne0[i];j++) // #black in ne0[i]+1~ne[i]-1
                {
                    l=(t[i]-t[ne[i]])-(sum(ne[i]-1)-sum(ne[i]-1-j)),r=(t[i]-t[ne[i]])-(sum(ne0[i]+j)-sum(ne0[i]));
                    if(l<=i && i<=r && ne0[i]==i) vis[i]=1;
                    l=max(l,pre[i]+2ll),r=min(r,(ll)i);
                    if(l<=r) pre1[i]=max(pre1[i],(int)r-1);
                }
            if(pre1[ne[i]]!=-1)
                for(j=0;j<=pre1[ne[i]]-1-ne0[i];j++) // #black in ne0[i]+1~pre1[ne[i]]-1
                {
                    l=(t[i]-t[ne[i]]+1)-(sum(pre1[ne[i]]-1)-sum(pre1[ne[i]]-1-j)),r=(t[i]-t[ne[i]]+1)-(sum(ne0[i]+j)-sum(ne0[i]));
                    if(l<=i && i<=r && ne0[i]==i) vis[i]=1;
                    l=max(l,pre[i]+2ll),r=min(r,(ll)i);
                    if(l<=r) pre1[i]=max(pre1[i],(int)r-1);
                }
        }
    // i=ne[0]; // i+1~ne1-1
    // for(pre[0]=1,j=1;j<=i;j++) pre[j]=pre[j-1]+(!t[j] || j==i); // can be pre-black
    // for(j=0;j<=ne1-1-i;j++) // #black in i+1~ne1-1
    // {
    //     l=(t[i]-t[ne[i]])-(sum(ne1-1)-sum(ne1-1-j)),r=(t[i]-t[ne[i]])-(sum(i+j)-sum(i));
    //     l=max(l,1ll),r=min(r,(ll)i);
    //     if(l>r) continue;
    //     if(l<=i) l--;
    //     if(r<i) r--;
    //     if(pre[r]-(l?pre[l-1]:0)) break;
    // }
    // assert(j<=ne1-1-i);
    // for(k=l;k<=r;k++)
    //     if(k==i || !t[k])
    //         break;
    // assert(k<=r);
    // // for(j=1;j<=n;j++) fprintf(stderr,"%d ",c[j]); fprintf(stderr,"\n");
    // c[k]=1,solve(i+1,ne1-1,t[i]-t[ne[i]]-(k+(k<i)));
    // for(i=ne[ne[0]];i<=n;i=ne[i]) fprintf(stderr,"%d: %d %d\n",i,vis[i],pre1[i]);
    i=ne[0];
    if(pre1[ne[i]]==i) vis[i]=1,pre1[i]=-1;
    else
    {
        for(s[0]=1,j=1;j<=i;j++) s[j]=s[j-1]+(!t[j]); // can be pre-black
        vis[i]=0,pre1[i]=-1;
        if(vis[ne[i]])
            for(j=0;j<=ne[i]-1-i;j++) // #black in i+1~ne[i]-1
            {
                l=(t[i]-t[ne[i]])-(sum(ne[i]-1)-sum(ne[i]-1-j)),r=(t[i]-t[ne[i]])-(sum(i+j)-sum(i));
                if(l<=i && i<=r && !s[i]) { vis[i]=1; break; }
                l=max(l-1,0ll),r=min(r-1,(ll)i);
                if(l<=r && s[r]-(l?s[l-1]:0)>0)
                {
                    for(k=l;k<=r;k++)
                        if(!k || !t[k])
                            break;
                    pre1[i]=k;
                    assert(k<=r);
                    break;
                }
            }
        if(!vis[i] && pre1[i]==-1 && pre1[ne[i]]!=-1)
            for(j=0;j<=pre1[ne[i]]-1-i;j++) // #black in i+1~pre1[ne[i]]-1
            {
                l=(t[i]-t[ne[i]]+1)-(sum(pre1[ne[i]]-1)-sum(pre1[ne[i]]-1-j)),r=(t[i]-t[ne[i]]+1)-(sum(ne0[i]+j)-sum(ne0[i]));
                if(l<=i && i<=r && !s[i]) { vis[i]=1; break; }
                l=max(l-1,0ll),r=min(r-1,(ll)i);
                if(l<=r && s[r]-(l?s[l-1]:0)>0)
                {
                    for(k=l;k<=r;k++)
                        if(!k || !t[k])
                            break;
                    pre1[i]=k;
                    assert(k<=r);
                    break;
                }
            }
        assert(vis[i] || pre1[i]!=-1);
    }
    if(vis[i]) pre1[i]=-1;
    for(i=ne[0];i<=n;i=ne[i])
    {
        if(c[i]==1) continue;
        if(vis[i]) c[i]=1,t[i]-=i/*,printf("%d: %d\n",i,i)*/;
        else assert(pre1[i]!=-1),c[pre1[i]]=1,t[i]-=pre1[i]+1/*,printf("%d: %d\n",i,pre1[i])*/;
        if(vis[ne[i]] && solve(ne0[i]+1,ne[i]-1,t[i]-t[ne[i]])) pre1[ne[i]]=-1;
        else assert(pre1[ne[i]]!=-1 && solve(ne0[i]+1,pre1[ne[i]]-1,t[i]-t[ne[i]]+1)),vis[ne[i]]=0;
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    for(solve(),i=0;i<n;i++)
        printf("%d",c[n-i]);
    printf("\n");
    return 0;
}