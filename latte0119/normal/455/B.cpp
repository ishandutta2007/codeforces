#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

struct node{
    node *nex[26];
    node(){
        rep(i,26)nex[i]=NULL;
    }
};

void insert(node *t,string &s,int i){
    if(s.size()==i)return;
    int c=s[i]-'a';
    if(t->nex[c]==NULL){
        t->nex[c]=new node();
    }
    insert(t->nex[c],s,i+1);
}


int N,K;

bool towin(node *t){
    bool res=false;
    rep(i,26)if(t->nex[i]!=NULL)res|=towin(t->nex[i])==false;
    return res;
}

bool tolose(node *t){
    bool latte=false;
    rep(i,26){
        if(t->nex[i]==NULL)continue;
        latte=true;
        if(tolose(t->nex[i])==false)return true;
    }
    if(latte)return false;
    return true;
}

signed main(){
    cin>>N>>K;
    node *root=new node();
    rep(i,N){
        string s;cin>>s;
        insert(root,s,0);
    }

    bool w=towin(root);
    bool l=tolose(root);

    if(!w){
        cout<<"Second"<<endl;
    }
    else if(l){
        cout<<"First"<<endl;
    }
    else if(K&1){
        cout<<"First"<<endl;
    }
    else{
        cout<<"Second"<<endl;
    }
    return 0;
}