#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int SIZE=200000;

int N;
int A[SIZE*2];

void lattemain(){
    cin>>N;
    rep(i,N)cin>>A[i];
    rep(i,N)A[i+N]=A[i];

    int mi=*min_element(A,A+N);
    int ma=0,pre=0;
    rep(i,N*2){
        if(A[i]==mi)pre=0;
        else pre++;
        ma=max(ma,pre);
    }
    cout<<ma+mi*N<<endl;
}

signed main(){
    cin.tie();ios_base::sync_with_stdio(false);
    lattemain();
}