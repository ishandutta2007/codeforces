#include<bits/stdc++.h>
using namespace std;

//#define int long long

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

int N;
char type[5555];
int A[5555],B[5555];

signed main(){
    cin>>N;
    rep(i,N)cin>>type[i]>>A[i]>>B[i],A[i]--;
    int ma=0;
    rep(i,366){
        int x=0,y=0;
        rep(j,N){
            if(A[j]<=i&&i<B[j]){
                if(type[j]=='M')x++;
                else y++;
            }
        }
        chmax(ma,min(x,y)*2);
    }
    cout<<ma<<endl;
    return 0;
}