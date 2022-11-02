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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int a[10];

signed main(){
    a[9]=1989;
    rep(i,9)a[i]=a[(i-1+10)%10]+1;

    int N;
    cin>>N;
    while(N--){
        string S;
        cin>>S;
        S=S.substr(4,S.size()-4);
        reverse(all(S));
        int y=a[S[0]-'0'];
        int d=10;
        reps(i,1,S.size()){
            while(true){
                y+=d;
                int tmp=y/d%10;
                if(tmp==S[i]-'0')break;
            }
            d*=10;
        }
        cout<<y<<endl;
    }
    return 0;
}