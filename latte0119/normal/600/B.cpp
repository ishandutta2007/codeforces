#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int main(){
    cin.tie();
    ios_base::sync_with_stdio(0);

    int N,M;cin>>N>>M;
    vint A(N);
    rep(i,N)cin>>A[i];
    sort(all(A));
    while(M--){
        int b;
        cin>>b;
        cout<<upper_bound(all(A),b)-A.begin()<<" ";
    }
    cout<<endl;
    return 0;
}