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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N,a[100];

signed main(){
    cin>>N;
    rep(i,N)cin>>a[i];

    if(find(a,a+N,1)==a+N){
        cout<<0<<endl;
        return 0;
    }

    int l=0,r=N-1;
    while(!a[l])l++;
    while(!a[r])r--;

    int ans=1;
    while(l<r){
        l++;
        int cnt=0;
        while(!a[l]){
            cnt++;l++;
        }
        ans*=(cnt+1);
    }
    cout<<ans<<endl;
    return 0;
}