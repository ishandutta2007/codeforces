#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

struct stree{
    ll (*op)(ll,ll);
    ll neu;
    ll *a;

    stree(ll (*oop)(ll,ll),ll nneu,ll *aa){
        op=oop;
        a=aa;
        neu=nneu;
    }
};

#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)

void stinit(stree& st, int n, int s, int e, ll *m){
    if(s+1==e)st.a[n]=m[s];
    else{
        stinit(st,LEFT(n),s,(s+e)/2,m);
        stinit(st,RIGHT(n),(s+e)/2,e,m);
        st.a[n]=st.op(st.a[LEFT(n)],st.a[RIGHT(n)]);
    }
}

void stupd(stree& st, int n, int s, int e, int p, int v){
    if(s+1==e)st.a[n]=v;
    else {
        if(p<(s+e)/2)
            stupd(st,LEFT(n),s,(s+e)/2,p,v);
        else
            stupd(st,RIGHT(n),(s+e)/2,e,p,v);
        st.a[n]=st.op(st.a[LEFT(n)],st.a[RIGHT(n)]);
    }
}

ll stqry(stree& st, int n, int s, int e, int a, int b){
    if(a>=e||b<=s)return st.neu;
    if(s>=a&&e<=b)return st.a[n];
    ll l = stqry(st,LEFT(n),s,(s+e)/2,a,b);
    ll r = stqry(st,RIGHT(n),(s+e)/2,e,a,b);
    return st.op(l,r);
}


ll mysum(ll a, ll b){
    return a+b;
}

ll v[200005];
ll v2[200005];
ll st1[400005];
ll st2[400005];

ll mymax(ll a, ll b){
    if(a==-1)return b;
    if(b==-1)return a;
    return v[a]>=v[b]?a:b;
}

int main(){
    int n,q,i;
    cin>>n>>q;
    for(i=0;i<n;++i){
        cin>>v[i];
        v2[i]=i;
    }
    stree stsum(mysum,0,st1);
    stree stmax(mymax,-1,st2);

    stinit(stsum,1,0,n,v);
    stinit(stmax,1,0,n,v2);

    while(q--){
        int op;
        cin>>op;
        switch(op){
            case 1:{
                int l,r;
                cin>>l>>r;
                cout<<stqry(stsum,1,0,n,l-1,r)<<endl;
                break;}
            case 2:{
                int l,r,x,pm;
                cin>>l>>r>>x;
                pm=stqry(stmax,1,0,n,l-1,r);
                while(pm>=0&&v[pm]>=x){
                    v[pm]=v[pm]%x;
                    stupd(stsum,1,0,n,pm,v[pm]);
                    stupd(stmax,1,0,n,pm,pm);
                    pm=stqry(stmax,1,0,n,l-1,r);
                }
                break;}
            case 3:{
                int k,x;
                cin>>k>>x;
                v[k-1]=x;
                stupd(stsum,1,0,n,k-1,x);
                stupd(stmax,1,0,n,k-1,k-1);
                break;}
            case 4:
                for(int i=0;i<n;++i)
                    cout<<v[i]<<' ';
                puts("");
                break;
        }
    }
}