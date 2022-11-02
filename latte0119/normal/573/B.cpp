#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int N;
int dist[100010];

signed main(){
    scanf("%d",&N);
    rep(i,N)scanf("%d",&dist[i+1]);
    N+=2;

    priority_queue<pint,vector<pint>,greater<pint>>que;
    rep(i,N)que.push(pint(dist[i],i));

    while(que.size()){
        pint p=que.top();que.pop();
        if(dist[p.se]<p.fi)continue;
        for(int dx=-1;dx<=1;dx+=2){
            int nex=p.se+dx;
            if(nex<0||nex>=N)continue;
            if(dist[nex]<=p.fi+1)continue;
            dist[nex]=p.fi+1;
            que.push(pint(dist[nex],nex));
        }
    }

    printf("%d\n",*max_element(dist,dist+N));
    return 0;
}