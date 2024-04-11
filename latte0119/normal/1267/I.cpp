#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
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
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}


int q(int a,int b){
    cout<<"? "<<a+1<<" "<<b+1<<endl;
    string s;cin>>s;
    if(s==">")return true;
    return false;
}

void solve(){
    int N;cin>>N;

    vint lo;
    for(int i=0;i<2*N;i+=2){
        int tmp=q(i,i+1);
        if(tmp)lo.pb(i+1);
        else lo.pb(i);
    }

    sort(all(lo),[&](int a,int b){
        return q(a,b);
    });


    int rem=N;
    vint lis;
    for(int i=N-1;i>0;i--){
        vint A,B;
        for(auto u:lis){
            if(q(lo[i],u))A.pb(u);
            else B.pb(u);
        }
        if(A.size()+1<=rem){
            lis=B;
            rem-=A.size()+1;
        }
        else{
            sort(all(A),[&](int a,int b){
                return q(a,b);
            });
            rem=0;
            break;
        }
        lis.pb(lo[i]^1);
    }
    if(rem){
        sort(all(lis),[&](int a,int b){
            return q(a,b);
        });
        q(lo[0],lis.back());
    }
    cout<<"!"<<endl;
}
signed main(){
    int T;cin>>T;
    while(T--)solve();
    return 0;
}