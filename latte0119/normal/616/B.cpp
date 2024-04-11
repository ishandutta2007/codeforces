#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int H,W;
int a[100];
signed main(){
    cin.tie();
    ios_base::sync_with_stdio(0);

    cin>>H>>W;
    fill_n(a,H,1001001001001001001ll);

    rep(i,H)rep(j,W){
        int x;cin>>x;a[i]=min(a[i],x);
    }
    cout<<*max_element(a,a+H)<<endl;

    return 0;
}