#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(A) (A).begin(),(A).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&A){
    ost<<"{";
    for(int i=0;i<A.size();i++){
        if(i)ost<<",";
        ost<<A[i];
    }
    ost<<"}";
    return ost;
}

int ans[1111][1111];
int A[1111];
void solve(int l,int r){
    int n=r-l;
    if(n==0)return;
    if(A[r-1]<n){
        solve(l,r-1);
        ans[n][r-1]=1;
        for(int i=0;i<A[r-1]-1;i++)ans[i][r-1]=1;
        return;        
    }

    if(A[l]==1){
        ans[n][l]=1;
        for(int i=l+1;i<r;i++)if(A[i]==n){
            ans[n][i]=1;
            A[i]--;
        }
        solve(l+1,r);
        return;
    }


    for(int i=l;i<r;i++){
        ans[n][i]=1;
        A[i]--;
    }
    solve(l+1,r);
    for(int i=0;i<A[l];i++)ans[i][l]=1;
}

signed main(){
    int N;scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    vint ord(N);iota(all(ord),0);
    sort(all(ord),[&](int a,int b){
        return A[a]<A[b];
    });

    sort(A,A+N);
    solve(0,N);

    vector<string>vec;
    rep(i,N+1){
        string s(N,'0');
        rep(j,N)s[ord[j]]=ans[i][j]+'0';
        if(count(all(s),'0')==N)continue;
        vec.pb(s);
    }
    cout<<vec.size()<<endl;
    for(auto &s:vec)cout<<s<<endl;
}