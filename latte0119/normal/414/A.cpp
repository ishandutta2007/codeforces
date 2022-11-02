#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

bool f[5555555];
vint p;
signed main(){
    fill_n(f,5555555,1);
    f[0]=f[1]=0;
    for(int i=2;i<5555555;i++){
        if(!f[i])continue;
        p.pb(i);
        for(int j=i+i;j<5555555;j+=i)f[j]=0;
    }
    int N,K;
    cin>>N>>K;
    if(N/2>K||(N==1&&K!=0)){
        cout<<-1<<endl;
        return 0;
    }

    if(N==1){
        cout<<1<<endl;
        return 0;
    }

    int tmp=K-(N/2-1);
    set<int>latte;
    cout<<tmp<<" "<<tmp*2<<" ";
    latte.insert(tmp);
    latte.insert(tmp*2);

    rep(i,N-2){
        while(latte.find(p.back())!=latte.end())p.pop_back();
        cout<<p.back()<<" ";
        latte.insert(p.back());
        p.pop_back();
    }
    cout<<endl;
    return 0;
}