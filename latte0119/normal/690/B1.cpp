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

int N;
int A[55][55];

signed main(){
    cin>>N;
    bool ex=false;
    rep(i,N)rep(j,N){
        char c;cin>>c;
        A[i][j]=c-'0';
        if(A[i][j])ex=true;
    }
    if(!ex){
        cout<<"No"<<endl;
        return 0;
    }

    int min_y=11111,max_y=-11111,min_x=11111,max_x=-11111;
    rep(i,N)rep(j,N){
        if(A[i][j]){
            chmin(min_y,i);
            chmax(max_y,i);
            chmin(min_x,j);
            chmax(max_x,j);
        }
    }
    rep(t0,2)rep(t1,2)rep(t2,2)rep(t3,2){
        int AA[55][55];
        bool ok=true;
        rep(i,N)rep(j,N)AA[i][j]=A[i][j];
        rep(i,N)rep(j,N){
            for(int dy=0;dy<=1;dy++){
                for(int dx=0;dx<=1;dx++){
                    int y=i+dy,x=j+dx;
                    if(y<0||y>N||x<0||x>N)continue;
                    if(min_y+t0<=y&&y<=max_y+t1&&min_x+t2<=x&&x<=max_x+t3)AA[i][j]--;
                }
            }
            if(AA[i][j]!=0){
                ok=false;
            }
        }
        if(ok){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}