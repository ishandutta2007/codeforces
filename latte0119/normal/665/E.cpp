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
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,f,n) for(int i=(int)(f);i<(int)(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

struct node{
    node *ch[2];
    int cnt;
    node():cnt(0){ch[0]=ch[1]=0;}
};

int N,K;
int A[1111111];

node *root;

void insert(node *t,int s,int d=29){
    t->cnt++;
    if(d<0)return;
    int tmp=s>>d&1;
    if(t->ch[tmp]==NULL){
        t->ch[tmp]=new node();
    }
    insert(t->ch[tmp],s,d-1);
}

int calc(node *t,int s,int d=29){
    if(t==0)return 0;
    if(d<0)return t->cnt;
    int tmp=s>>d&1;
    if(K>>d&1){
        if(tmp)return calc(t->ch[0],s,d-1);
        else return calc(t->ch[1],s,d-1);
    }
    else{
        if(tmp)return calc(t->ch[1],s,d-1)+(t->ch[0]?t->ch[0]->cnt:0);
        else return calc(t->ch[0],s,d-1)+(t->ch[1]?t->ch[1]->cnt:0);
    }
}

signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%lld",&A[i]);

    root=new node();

    int ans=0;
    int sum=0;
    insert(root,sum);
    rep(i,N){
        sum^=A[i];
        ans+=calc(root,sum);
        insert(root,sum);
    }

    printf("%lld\n",ans);
    return 0;
}